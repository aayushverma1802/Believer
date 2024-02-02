class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &Grid)
    {
        if (i >= 0 and j >= 0 and Grid[i][j] == 1)
        {
            return 0;
        }
        if (j == 0 and i == 0)
        {
            return 1;
        }
        if (i < 0 or j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = solve(i - 1, j, dp, Grid);
        int right = solve(i, j - 1, dp, Grid);
        return dp[i][j] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &Grid)
    {
        int n = Grid.size();
        int m = Grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, dp, Grid);
    }
};
