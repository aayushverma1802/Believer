class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return {nums[0]};
        }
        vector<int> o, e;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                o.push_back(nums[i]);
            }
            else
            {
                e.push_back(nums[i]);
            }
        }
        vector<int> ans;
        int i = 0;
        while (i < o.size())
        {
            ans.push_back(o[i]);
            i++;
        }
        i = 0;
        while (i < e.size())
        {
            ans.push_back(e[i]);
            i++;
        }

        return ans;
    }
};