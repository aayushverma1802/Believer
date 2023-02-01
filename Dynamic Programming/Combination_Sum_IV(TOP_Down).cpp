class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, n - nums[i], dp);
        }
        dp[n] = ans;
        return dp[n];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);

        return solve(nums, target, dp);
    }
};