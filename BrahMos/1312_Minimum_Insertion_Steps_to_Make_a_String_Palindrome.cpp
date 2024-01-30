class Solution
{
public:
    int solve(string &t1, string &t2, int n, int m, int i, int j, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (j == m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (t1[i] == t2[j])
        {
            return ans = 1 + solve(t1, t2, n, m, i + 1, j + 1, dp);
        }

        ans = max(solve(t1, t2, n, m, i + 1, j, dp), solve(t1, t2, n, m, i, j + 1, dp));
        return dp[i][j] = ans;
    }

    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        int m = t.size();
        vector<vector<int>> dp(1000, vector<int>(1000, -1));
        int ans = solve(s, t, n, m, 0, 0, dp);
        return s.size() - ans;
    }
};