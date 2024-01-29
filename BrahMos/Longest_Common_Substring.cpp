int solve(string &str1, string &str2, int n, int m, int &maxi, int i, int j, vector<vector<int>> &dp)
{
    if (i > n or j > m)
    {
        return 0;
    }
    int ans = 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (str1[i] == str2[j])
    {
        ans = 1 + solve(str1, str2, n, m, maxi, i + 1, j + 1, dp);
        dp[i][j] = ans;
    }
    maxi = max(ans, maxi);
    solve(str1, str2, n, m, maxi, i + 1, j, dp);
    solve(str1, str2, n, m, maxi, i, j + 1, dp);
    return dp[i][j] = ans;
}
int lcs(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.size();
    int m = str2.size();
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(str1, str2, n - 1, m - 1, maxi, 0, 0, dp);
    return maxi;
}