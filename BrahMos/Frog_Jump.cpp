#include <bits/stdc++.h>
int mi = INT_MAX;
int solve(vector<int> &heights, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int o = solve(heights, n - 1, dp) + abs(heights[n] - heights[n - 1]);
    int t = INT_MAX;
    if (n > 1)
    {
        t = solve(heights, n - 2, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(o, t);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return solve(heights, n - 1, dp);
}