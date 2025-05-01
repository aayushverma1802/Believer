class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());

        if (stones.size() <= 1)
        {
            return stones[0];
        }

        while (!pq.empty() && pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            cout << x << " ";

            int y = pq.top();
            pq.pop();
            cout << y << " ";

            if (x != y)
            {
                pq.push(abs(x - y));
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
