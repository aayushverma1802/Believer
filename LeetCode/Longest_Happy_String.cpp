class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
        {
            pq.push({a, 'a'});
        }
        if (b > 0)
        {
            pq.push({b, 'b'});
        }
        if (c > 0)
        {
            pq.push({c, 'c'});
        }

        string res = "";
        while (pq.size() > 1)
        {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();

            if (it1.first >= 2)
            {
                res += it1.second;
                res += it1.second;
                it1.first -= 2;
            }
            else // freq 1 hogi
            {
                res += it1.second;
                it1.first -= 1;
            }

            if (it2.first >= 2 && it2.first >= it1.first) // very important condition
            {
                res += it2.second;
                res += it2.second;
                it2.first -= 2;
            }
            else // freq 1 hogi
            {
                res += it2.second;
                it2.first -= 1;
            }

            if (it1.first > 0)
            {
                pq.push(it1);
            }

            if (it2.first > 0)
            {
                pq.push(it2);
            }
        }

        if (pq.size() == 1)
        {
            auto it = pq.top();
            pq.pop();

            if (it.first >= 2)
            {
                res += it.second;
                res += it.second;
                it.first -= 2;
            }
            else
            {
                res += it.second;
                it.first -= 1;
            }
        }

        return res;
    }
};