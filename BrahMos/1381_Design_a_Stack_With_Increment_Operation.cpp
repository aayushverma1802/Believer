class CustomStack
{
public:
    int n = 0;
    vector<int> s;
    CustomStack(int maxSize)
    {
        n = maxSize;
        vector<int> s(n, 0);
    }
    vector<int> st = s;
    void push(int x)
    {
        if (st.size() < n)
            st.push_back(x);
    }

    int pop()
    {
        if (st.empty())
        {
            return -1; // Return -1 if the stack is empty
        }
        int ele = st[st.size() - 1];
        st.pop_back();
        return ele;
    }

    void increment(int k, int val)
    {
        if (st.size() < k)
        {
            for (int i = 0; i < st.size(); i++)
            {
                st[i] = st[i] + val;
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                st[i] = st[i] + val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */