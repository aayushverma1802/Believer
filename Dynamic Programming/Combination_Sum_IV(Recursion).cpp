class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, n - nums[i]);
        }
        return ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        return solve(nums, target);
    }
};