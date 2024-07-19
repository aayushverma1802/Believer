class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int edgew = it.second;
                int adjnode = it.first;
                if (dis + edgew < dist[adjnode])
                {
                    dist[adjnode] = dis + edgew;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        // return dist;
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (dist[k] == 0 and dist[i] == 1e9)
            {
                return -1;
            }
            else
            {
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};