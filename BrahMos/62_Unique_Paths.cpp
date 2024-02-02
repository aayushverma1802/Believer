class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 or j < 0)
        {
            return 0;
        }
        if (j == 0 and i == 0)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = solve(i - 1, j, dp);
        int right = solve(i, j - 1, dp);
        return dp[i][j] = left + right;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, dp);
    }
};