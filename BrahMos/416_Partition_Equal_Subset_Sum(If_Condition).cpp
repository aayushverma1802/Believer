
class Solution
{
public:
    bool solve(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }
        if (n == 0)
        {
            return nums[0] == sum;
        }
        if (sum < 0)
        {
            return false;
        }

        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        bool nt = solve(nums, n - 1, sum, dp);
        bool t = false;
        if (sum >= nums[n])
            t = solve(nums, n - 1, sum - nums[n], dp);

        return dp[n][sum] = t or nt;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
        {
            return false;
        }
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(nums, n - 1, sum, dp);
    }
};