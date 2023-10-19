#include <bits/stdc++.h>
int solve(vector<int> &v, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int right = INT_MAX;

    int left = abs(v[n] - v[n - 1]) + solve(v, n - 1, dp);
    if (n > 1)
    {
        right = abs(v[n] - v[n - 2]) + solve(v, n - 2, dp);
    }
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(heights, n - 1, dp);
}