class MedianFinder
{
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

public:
    MedianFinder()
    {
        // s will be max-heap
        priority_queue<int> s;
        // g will be min-heap
        priority_queue<int, vector<int>, greater<int>> g;
    }

    void addNum(int num)
    {
        // if s is empty we push in s
        if (s.size() == 0)
        {
            s.push(num);
            return;
        }
        // if s size is greater than g.size()
        if (s.size() > g.size())
        {
            // data to be pushed is greater then top element of s
            // we are pushing the top element of s in g then
            // pushing it in s to maintain
            // (s.size() >= g.size() the size of both

            if (num < s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            // num > s.top() so we push in g
            else
            {
                g.push(num);
            }
        }
        else
        {
            // same logic as above
            if (num < s.top())
            {
                s.push(num);
            }
            else
            {
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }

    double findMedian()
    {
        if (s.size() == g.size())
        {
            return (double)(s.top() + g.top()) / 2.0;
        }
        else
        {
            return (double)s.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */