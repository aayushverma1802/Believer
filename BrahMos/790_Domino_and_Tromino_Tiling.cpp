class Solution
{
public:
    vector<int> dp;
    const int mod = 1e9 + 7;
    int solve(int n)
    {

        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n == 1)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        if (n == 2)
        {
            return 2;
        }
        if (n == 3)
        {
            return 5;
        }
        return dp[n] = (2LL * solve(n - 1) + solve(n - 3)) % mod;
    }
    int numTilings(int n)
    {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};