class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans;
        int a = 0;
        // nums.insert(begin(nums),0);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            a += nums[i];
            ans.push_back(a);
        }
        return ans;
    }
};