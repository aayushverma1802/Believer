class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        nums.clear();
        for (auto i : m)
        {
            cout << i.first << i.second << endl;
            if (i.second == 1)
            {
                nums.push_back(i.first);
            }
            else if (i.second >= 2)
            {
                nums.push_back(i.first);
                nums.push_back(i.first);
                i.second = 0;
            }
        }
        return nums.size();
    }
};