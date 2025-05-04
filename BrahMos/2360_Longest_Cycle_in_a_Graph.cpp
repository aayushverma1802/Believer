class Solution
{
public:
    int maxi = -1;

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, vector<int> &depth, int d)
    {
        vis[node] = pathVis[node] = true;
        depth[node] = d;

        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pathVis, depth, d + 1);
            }
            else if (pathVis[i])
            {
                // Found a cycle
                maxi = max(maxi, abs(depth[i] - d) + 1);
            }
        }

        pathVis[node] = false;
    }

    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<bool> vis(n, false), pathVis(n, false);
        vector<int> depth(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pathVis, depth, 0);
            }
        }

        return maxi;
    }
};
