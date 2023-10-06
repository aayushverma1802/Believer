class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 1 or n == 0)
        {
            return dp[n] = 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n - 1; i++)
        {
            int pro = i * max(n - i, solve(n - i, dp));
            ans = max(pro, ans);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n)
    {
        vector<int> dp(n + 6, -1);
        return solve(n, dp);
    }
};