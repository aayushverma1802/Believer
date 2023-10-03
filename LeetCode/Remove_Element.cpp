class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> v;
        for (auto i : nums)
        {
            if (i != val)
            {
                v.push_back(i);
            }
        }
        nums = v;
        return v.size();
    }
};