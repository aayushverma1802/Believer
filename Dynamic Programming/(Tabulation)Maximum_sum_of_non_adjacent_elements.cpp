#include <bits/stdc++.h>
int solve(vector<int> &nums)
{
    // Base case
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int incl = dp[nums, i - 2] + nums[i];
        int excl = dp[nums, i - 1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    int ans = solve(nums);
    return ans;
}