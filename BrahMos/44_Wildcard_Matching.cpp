class Solution
{
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
        {
            return true;
        }
        if (i > 0 and j == 0)
        {
            return false;
        }

        if (i == 0 and j > 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        // match
        if (s[i - 1] == p[j - 1] or p[j - 1] == '?')
        {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        else if (p[j - 1] == '*')
        {
            return dp[i][j] = (solve(s, p, i - 1, j, dp) or solve(s, p, i, j - 1, dp));
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, s.size(), p.size(), dp);
    }
};