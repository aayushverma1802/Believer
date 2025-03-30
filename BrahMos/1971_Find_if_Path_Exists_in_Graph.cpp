class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, int destination,
             vector<bool> &vis)
    {
        vis[node] = true;
        for (auto &i : adj[node])
        {
            if (vis[i] == false)
                dfs(i, adj, destination, vis);
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination)
    {
        vector<vector<int>> adj(n);

        vector<bool> vis(n, false);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(source, adj, destination, vis);

        return vis[destination];
    }
};