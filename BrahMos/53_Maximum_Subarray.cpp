class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = 0;
        int max_ans = INT_MIN;

        if (nums.size() == 1)
        {
            return nums[0];
        }

        for (auto i : nums)
        {
            curr += i;
            if (curr > max_ans)
            {
                max_ans = curr;
            }
            if (curr < 0)
            {
                curr = 0;
            }
        }
        return max_ans;
    }
};