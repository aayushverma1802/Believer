class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (s.empty() or nums[s.top()] > nums[i])
            {
                s.push(i);
            }
        }
        int ans = 0;
        int j = n - 1;
        while (j >= 0)
        {
            while (!s.empty() and nums[s.top()] <= nums[j])
            {
                int i = s.top();
                ans = max(ans, j - i);
                s.pop();
            }
            j--;
        }
        return ans;
    }
};