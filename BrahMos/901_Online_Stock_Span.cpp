class StockSpanner
{
public:
    stack<pair<int, int>> st;

    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (st.empty() == false and price >= st.top().first)
        {
            span += st.top().second;
            // st.push({price,span});
            st.pop();
        }
        st.push(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */