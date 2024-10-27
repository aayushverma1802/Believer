class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            string curr = words[i]; 
            for (auto &c : curr)
            {
                freq[i][c - 'a']++;
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            int mn = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                mn = min(mn, freq[j][i]);
            }
            while (mn > 0)
            {
                ans.push_back(string(1, i + 'a'));
                mn--;
            }
        }
        return ans;
    }
};
