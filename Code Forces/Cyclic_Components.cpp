#include <iostream>
#include <vector>
using namespace std;
bool check = true;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    // Cyclic component
    if (adj[node].size() != 2)
    {

        check = false;
        // return;
    }
    for (auto i : adj[node])
    {

        // Normal dfs
        if (vis[i] == false)
        {

            dfs(i, adj, vis);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int result = 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    // Traverse the Full graph

    for (int i = 0; i <n; i++)
    {
        if (vis[i] == false)
        {
            check = true;

            dfs(i, adj, vis);
            if (check == true)
            {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}