class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (auto i : nums)
        {
            mp.insert(make_pair(i, cnt));
            cnt++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int key = target - nums[i];
            if (mp.find(key) != mp.end() and mp[key] != i)
            {
                return {i, mp[key]};
            }
        }
        return ans;
    }
};