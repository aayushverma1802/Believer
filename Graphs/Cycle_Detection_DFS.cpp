//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src, int par, vector<int> adj[], vector<bool> &vis)
    {
        vis[src] = true;
        for (auto x : adj[src])
        {
            if (!vis[x])
            {
                if (dfs(x, src, adj, vis))
                {
                    return true;
                }
            }
            else if (x != par)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool f = dfs(i, -1, adj, vis);
                if (f)
                {
                    return true;
                }
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
