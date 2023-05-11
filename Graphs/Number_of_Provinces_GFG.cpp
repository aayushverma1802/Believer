//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int node, vector<int> adjls[], vector<bool> &vis)
    {
        vis[node] = 1;
        for (auto it : adjls[node])
        {
            if (!vis[it])
            {
                dfs(it, adjls, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int n = adj.size();
        vector<int> adjls[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // i!=j means no self loop;
                if (adj[i][j] == 1 and i != j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjls, vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends