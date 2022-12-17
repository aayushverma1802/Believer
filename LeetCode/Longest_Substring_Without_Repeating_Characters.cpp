class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> x;
        int max = 0;
        int st = 0;
        int e = 0;
        while (st < s.size())
        {
            auto it = x.find(s[st]);
            if (it == x.end())
            {
                if (st - e + 1 > max)
                {
                    max = st - e + 1;
                }
                x.insert(s[st]);
                st++;
            }
            else
            {
                x.erase(s[e]);
                e++;
            }
        }
        return max;
    }
};