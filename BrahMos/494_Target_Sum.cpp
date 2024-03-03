class Solution
{
public:
    void rec(int i, int &ans, vector<int> &nums, int t, int val)
    {
        if (i == nums.size())
        {
            if (t == val)
            {
                ans++;
            }
            return;
        }

        rec(i + 1, ans, nums, t, val + nums[i]);
        rec(i + 1, ans, nums, t, val - nums[i]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int ans = 0;
        rec(0, ans, nums, target, 0);
        return ans;
    }
};