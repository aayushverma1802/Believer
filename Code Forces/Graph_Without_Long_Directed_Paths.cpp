#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bipartite(vector<vector<int>> &adj, int u, vector<bool> &col, vector<bool> &vis)

{
    vis[u] = true;
    for (auto i : adj[u])
    {
        if (vis[i] && col[u] == col[i]) // If already visited and same color, return false
        {
            return false;
        }
        else if (!vis[i])
        {
            col[i] = !col[u]; // Assign opposite color
            if (!bipartite(adj, i, col, vis))
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // We will use the bipartite graph concept here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> temp;
    vector<bool> col(n + 1, false);
    vector<bool> vis(n + 1, false);

    for (int j = 0; j < m; j++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        temp.push_back({a, b});
    }

    bool check = false;

    col[1] = 0;
    string dis = "";
    check = bipartite(adj, 1, col, vis);
    if (check == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++)
        {
            int u = temp[i].first;
            if (col[u] == 0)
            {
                dis += "0";
            }
            else
            {
                dis += "1";
            }
        }
    }
    cout << dis;

    return 0;
}