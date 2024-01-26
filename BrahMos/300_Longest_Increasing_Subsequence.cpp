class Solution
{
public:
    int solve(vector<int> &nums, int n, int i, int prev, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        int take = 0;
        if (prev == -1 or nums[prev] < nums[i])
        {
            take = 1 + solve(nums, n, i + 1, i, dp);
        }
        int ntake = solve(nums, n, i + 1, prev, dp);
        return dp[i][prev + 1] = max(ntake, take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};