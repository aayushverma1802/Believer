class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return nums;
        }
        else if (k > nums.size() / 2)
        {
            vector<int> temp(nums.size(), -1);
            return temp;
        }
        int n = nums.size();
        vector<int> ans(n, -1);
        int i = 0;
        long long int sum_temp = 0;
        for (int j = 0; j < n; j++)
        {
            sum_temp += nums[j];
            if (j - i + 1 == k * 2 + 1)
            {

                ans[i + k] = sum_temp / (k * 2 + 1);
                sum_temp -= nums[i];
                i++;
            }
        }
        return ans;
    }
};