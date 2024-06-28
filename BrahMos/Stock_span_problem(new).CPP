vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans(n);       // To store the span values
    stack<pair<int, int>> st; // Pair of (price, span)

    for (int i = 0; i < n; i++)
    {
        int span = 1;

        // While the stack is not empty and the top element's price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price[i])
        {
            span += st.top().second; // Add the span of the top element to the current span
            st.pop();                // Remove the top element
        }

        // Push the current price and its span to the stack
        st.push({price[i], span});

        // Store the span in the result array
        ans[i] = span;
    }

    return ans;
}
