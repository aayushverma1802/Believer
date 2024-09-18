class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        int size = t.size();
        for (int i = 0; i < size; i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];
            if (m1.find(ch1) != m1.end() and m1[ch1] != ch2 or
                m2.find(ch2) != m2.end() and m2[ch2] != ch1)
            {
                return false;
            }
            m1[ch1] = ch2;
            m2[ch2] = ch1;
        }
        return true;
    }
};