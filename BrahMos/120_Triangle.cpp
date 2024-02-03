class Solution
{
public:
    int solve(vector<vector<int>> &t, int i, int j, int n, vector<vector<int>> &dp)
    {
        if (i == n - 1)
        {
            return t[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int d = t[i][j] + solve(t, i + 1, j, n, dp);
        int dg = t[i][j] + solve(t, i + 1, j + 1, n, dp);
        return dp[i][j] = min(dg, d);
        // return ans;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(triangle, 0, 0, n, dp);
    }
};