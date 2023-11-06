class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        if (nums.size() == 0)
        {
            return 0;
        }
        int lng = 1;
        for (auto i : nums)
        {
            s.insert(i);
        }

        for (auto i : s)
        {
            if (s.find(i - 1) == s.end())
            {
                int cnt = 1;
                int x = i;
                while (s.find(x + 1) != s.end())
                {
                    cnt++;
                    x++;
                }
                lng = max(lng, cnt);
            }
        }
        return lng;
    }
};