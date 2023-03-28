class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans += nums[i];
            }
        }
        return ans;
    }
};