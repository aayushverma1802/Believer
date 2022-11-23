//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    const int N = 1e+7;
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> h;
        int vis[V] = {0};
        vis[0] = 1;

        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            h.push_back(node);
            // vector<int>:: iterator it;
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return h;
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends