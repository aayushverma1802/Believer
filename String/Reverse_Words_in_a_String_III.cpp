class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int r = 0;
        while (i < s.size())
        {
            while (r < s.size() and s[r] != ' ')
            {
                r++;
            }
            reverse(s.begin() + i, s.begin() + r);
            i = r + 1;
            r = i;
        }
        return s;
    }
};