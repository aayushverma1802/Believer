class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while ((st.empty() == false) and (i == n or heights[st.top()] >= heights[i]))
            {
                int len = heights[st.top()];
                st.pop();
                int bre;
                if (st.empty())
                {

                    bre = i;
                }
                else
                {
                    bre = i - st.top() - 1;
                }
                ans = max(ans, len * bre);
            }
            st.push(i);
        }

        return ans;
    }
};