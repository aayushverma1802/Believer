class Solution
{
public:
    string generate_Word(string word)
    {
        int arr[26] = {0};

        for (auto &i : word)
        {
            arr[i - 'a']++;
        }
        string new_word = "";
        for (int i = 0; i < 26; i++)
        {
            // if(arr[i]>0)
            new_word += string(arr[i], i + 'a');
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Brute Force
        //  map<string, vector<string>> m;
        //  vector<vector<string>> ans;

        // for (auto i : strs) {
        //     string temp = i;
        //     sort(temp.begin(), temp.end());
        //     m[temp].push_back(i);
        // }
        // for (auto i : m) {
        //     ans.push_back(i.second);
        // }
        // return ans;

        // Optimized
        map<string, vector<string>> m;
        for (auto &i : strs)
        {
            string word = generate_Word(i);
            m[word].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto &i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};