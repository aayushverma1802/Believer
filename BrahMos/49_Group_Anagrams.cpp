class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        vector<vector<string>> ans;

        for (auto i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};