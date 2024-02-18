class Solution
{
public:
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
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int total_sum = 0;
        for (auto i : nums)
        {
            total_sum += i;
        }

        int total = total_sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));

        if (total_sum % 2 != 0)
        {
            return false;
        }

        return solve(n - 1, total, nums, dp);
    }
};