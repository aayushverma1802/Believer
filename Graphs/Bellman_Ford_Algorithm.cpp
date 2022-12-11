//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        // Code here

        // n-1 times
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 1; i <= V; i++)
        {
            // traverse on edge list
            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] != 1e8 and ((dist[u] + wt) < dist[v]))
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // check for negative cycle
        bool flag = 0;

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e8 and ((dist[u] + wt) < dist[v]))
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            return dist;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends