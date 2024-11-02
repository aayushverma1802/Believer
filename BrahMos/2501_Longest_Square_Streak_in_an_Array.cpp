class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        set<long long int> s(nums.begin(), nums.end());
        int ans = INT_MIN;
        for (auto &i : s)
        {
            long long int num = i;
            int count = 0;
            while (s.find(num) != s.end())
            {
                count++;
                num *= num;
            }
            ans = max(ans, count);
        }
        return ans >= 2 ? ans : -1;
    }
};