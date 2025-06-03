class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, maxi = INT_MIN;
        int last_idx_zero = -1;
        while (j < n)
        {
            if (nums[j] == 0)
            {
                i = last_idx_zero + 1;
                last_idx_zero = j;
            }
            maxi = max(maxi, j - i);
            j++;
        }
        return maxi;
    }
};