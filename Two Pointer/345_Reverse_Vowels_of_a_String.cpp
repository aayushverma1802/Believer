class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0;
        int n = s.length();
        int j = n - 1;
        set<char> st;
        st.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        while (i < j)
        {
            if ((st.find(s[i]) != st.end()) && (st.find(s[j]) != st.end()))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if ((st.find(s[i]) == st.end()))
            {
                i++;
            }
            else if ((st.find(s[j]) == st.end()))
            {

                j--;
            }
        }
        return s;
    }
};