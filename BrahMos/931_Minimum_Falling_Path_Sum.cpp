class Solution
{
public:
    int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 or j > mat.size() - 1)
        {
            return 1e9;
        }
        if (i == 0)
        {
            return mat[i][j];
        }
        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }
        int a = mat[i][j] + solve(mat, i - 1, j - 1, dp);
        int b = mat[i][j] + solve(mat, i - 1, j, dp);
        int c = mat[i][j] + solve(mat, i - 1, j + 1, dp);
        return dp[i][j] = min(a, min(b, c));
    }
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 1e8;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        for (int i = 0; i < n; i++)
        {
            maxi = min(maxi, solve(mat, n - 1, i, dp));
        }
        return maxi;
    }
};