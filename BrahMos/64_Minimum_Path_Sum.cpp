class Solution
{
public:
    int solve(vector<vector<int>> &v, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 and n == 0)
        {
            return v[0][0];
        }
        if (m < 0 or n < 0)
        {
            return 1e9;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int right = v[m][n] + solve(v, m - 1, n, dp);
        int down = v[m][n] + solve(v, m, n - 1, dp);
        return dp[m][n] = min(right, down);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, m - 1, n - 1, dp);
    }
};