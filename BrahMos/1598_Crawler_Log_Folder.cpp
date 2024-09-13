class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        for (auto &i : logs)
        {
            if (i == "../")
            {
                if (st.empty() == false)
                {
                    st.pop();
                }
            }
            else if (i != "./")
            {
                st.push(i);
            }
        }
        return st.size();
    }
};