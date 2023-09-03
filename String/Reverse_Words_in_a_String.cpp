class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                // skip spaces
                continue;
            }
            string word = "";
            while (s[i] != ' ' and i < s.length())
            {
                // store continuous letters into word
                word.push_back(s[i]);
                i++;
            }
            st.push(word); // push word to the stack
        }
        while (st.empty() == false)
        {
            ans += st.top() + " ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};