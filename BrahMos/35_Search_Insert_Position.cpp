class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = nums.size();
        while (s <= e)
        {
            int i = s + (e - s) / 2;
            if (nums[i] >= target)
            {
                ans = i;
                e = i - 1;
            }
            else
            {
                s = i + 1;
            }
        }
        return ans;
    }
};
