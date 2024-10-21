class Solution
{
public:
    vector<string> temp;
    bool pan(int i, int j, string s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int index, string s, vector<vector<string>> &ans)
    {
        if (index == s.length())
        {
            return ans.push_back(temp);
        }
        for (int i = index; i < s.size(); i++)
        {
            if (pan(index, i, s))
            {
                temp.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        solve(0, s, ans);
        return ans;
    }
};