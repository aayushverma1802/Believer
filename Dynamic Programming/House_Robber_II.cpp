class Solution
{
public:
    int solve(vector<int> &kp, int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return kp[n];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int incl = solve(kp, n - 2, dp) + kp[n];
        int excl = solve(kp, n - 1, dp);
        return dp[n] = max(incl, excl);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> first, second;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                first.push_back(nums[i]);
            }
            if (i != 0)
            {
                second.push_back(nums[i]);
            }
        }
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        return max(solve(first, n - 2, dp1), solve(second, n - 2, dp2));
    }
};