//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], int node, int parent, vector<bool> &vis)
    {
        vis[node] = true;
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                if (dfs(adj, adjNode, node, vis) == true)
                {
                    return true;
                }
            }
            else if (adjNode != parent)
            {
                return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if ((dfs(adj, i, -1, vis)) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends