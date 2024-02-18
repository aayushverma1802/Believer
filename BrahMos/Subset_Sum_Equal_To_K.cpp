#include <bits/stdc++.h>
bool solve(int n, int target, vector<int> &a, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return a[0] == target;
    }
    if (target < 0)
    {
        return false;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    bool notTake = solve(n - 1, target, a, dp);
    bool take = solve(n - 1, target - a[n], a, dp);

    return dp[n][target] = take or notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}
