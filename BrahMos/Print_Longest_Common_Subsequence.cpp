string solve(string &s1, string &s2, int i, int j, vector<vector<string>> &dp)
{
    if (i == s1.size() || j == s2.size())
        return dp[i][j] = "";

    if (dp[i][j] != "")
        return dp[i][j];
    string ans;
    if (s1[i] == s2[j])
    {
        ans = s1[i] + solve(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        string case1 = solve(s1, s2, i + 1, j, dp);
        string case2 = solve(s1, s2, i, j + 1, dp);
        if (case1.size() > case2.size())
        {
            ans = case1;
        }
        else
        {
            ans = case2;
        }
    }
    return dp[i][j] = ans;
}

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<string>> dp(n + m, vector<string>(m + n, ""));
    return solve(s1, s2, 0, 0, dp);
}