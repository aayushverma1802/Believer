class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        for (auto i : m)
        {
            if (m[i.first] == 1)
            {
                cout << i.first << i.second;
                return i.first;
            }
        }
        return -1;
    }
};