class Solution
{
public:
    string b;
    vector<vector<string>> ans;
    unordered_map<string, int> m;
    void dfs(string end, vector<string> &seq)
    {
        if (end == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = m[end];
        int q = end.size();
        for (int i = 0; i < q; i++)
        {
            char temp = end[i];
            for (char p = 'a'; p <= 'z'; p++)
            {
                end[i] = p;
                if (m.find(end) != m.end() && m[end] + 1 == steps)
                {
                    seq.push_back(end);
                    dfs(end, seq);
                    seq.pop_back();
                }
            }
            end[i] = temp;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        b = beginWord;
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        m[beginWord] = 1;
        int sz = beginWord.size();
        s.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            int steps = m[word];
            q.pop();
            if (word == endWord)
                break;
            for (int i = 0; i < sz; i++)
            {
                string temp = word;
                for (char p = 'a'; p <= 'z'; p++)
                {
                    temp[i] = p;
                    if (s.find(temp) != s.end())
                    {
                        s.erase(temp);
                        q.push({temp});
                        m[temp] = steps + 1;
                    }
                }
            }
        }

        if (m.find(endWord) != m.end())
        {
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord, temp);
        }
        return ans;
        /*TLE*/
        /*
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int level=0;
        while(!q.empty())
        {
            vector<string> v=q.front();
            q.pop();
            if(v.size()>level){
                level++;
                for(auto it:used)
                {
                    s.erase(it);
                }
            }
            string word = v.back();
            if(word==endWord)
            {
                if(ans.size()==0)
                ans.push_back(v);
                else
                 if(ans[0].size()==v.size())
                    ans.push_back(v);

            }
            for(int i=0;i<word.length();i++)
            {
                string temp=word;
                for(char p='a';p<='z';p++)
                {
                    temp[i]=p;
                    if(s.find(temp)!=s.end())
                    {
                        v.push_back(temp);
                        q.push(v);
                        used.push_back(temp);
                        v.pop_back();
                    }
                }
            }
        }
            return ans;
        */
    }
};