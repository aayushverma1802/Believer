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

        vector<int> dp1(n + 1, -1);

        vector<int> dp2(n + 1, -1);
        vector<int> temp1, temp2;
        for (int i = 1; i < n; i++)
        {
            temp1.push_back(nums[i]);
        }
        // vector<int>temp2;
        for (int i = 0; i < n - 1; i++)
        {
            temp2.push_back(nums[i]);
        }
        return max(solve(temp1, n - 2, dp1), solve(temp2, n - 2, dp2));
    }
};