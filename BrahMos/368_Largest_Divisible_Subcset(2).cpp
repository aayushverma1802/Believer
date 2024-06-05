class Solution
{
public:
    vector<int> ans;
    // vector<int> dp;
    void lds(vector<int> temp, int i, int prev, vector<int> &nums, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            if (temp.size() > ans.size())
                ans = temp;
            return;
        }
        // We can't directly use temp.size() without typecasting because it will return an unsigned int and hence if() will not work.
        if ((int)temp.size() > dp[i] && (nums[i] % prev == 0))
        {
            dp[i] = temp.size();
            temp.push_back(nums[i]);
            lds(temp, i + 1, nums[i], nums, dp);
            temp.pop_back();
        }
        lds(temp, i + 1, prev, nums, dp);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // for(int i=0;i<=nums.size();i++) dp.push_back(-1);
        vector<int> dp(nums.size(), -1);
        vector<int> temp;
        lds(temp, 0, 1, nums, dp);
        return ans;
    }
};