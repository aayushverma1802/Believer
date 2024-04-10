class Solution
{
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis,
                  vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;

        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> vis(V + 1, 0);
        vector<int> pathVis(V + 1, 0);

        vector<int> safeNode;
        vector<int> check(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        // return false;

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};