class Solution
{ 
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &pp)
    {
        int V = pp.size();
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> adj[V];

        for (int i = 0; i < V; i++)
        {
            for (auto it : pp[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (q.empty() == false)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto i : adj[node])
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};