//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    // bool check(int node , vector<bool> &vis,vector<int>adj[],vector<bool>&dfs){
    bool check(int node, vector<bool> &vis, vector<int> adj[], vector<bool> &pathvis)
    {
        vis[node] = true;
        pathvis[node] = true;
        for (auto x : adj[node])
        {
            if (vis[x] == false)
            {
                bool cycle = check(x, vis, adj, pathvis);
                if (cycle)
                {
                    return true;
                }
            }
            else if (pathvis[x])
            {
                return true;
            }
        }
        pathvis[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V, false);
        vector<bool> pathvis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool f = check(i, vis, adj, pathvis);
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

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends