class MyQueue
{
public:
    deque<int> q;
    MyQueue()
    {
    }

    void push(int x)
    {
        q.push_back(x);
    }

    int pop()
    {
        int val = q.front();
        q.pop_front();
        return val;
    }

    int peek()
    {
        int val = q.front();
        return val;
    }

    bool empty()
    {
        if (q.empty() == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */