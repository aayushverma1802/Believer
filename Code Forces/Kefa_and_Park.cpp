#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int result = 0; // Count of valid restaurants

void dfs(int node, int cat_count, int m, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &pos) {
    vis[node] = true;

    // If the current node has a cat, increase the count; otherwise, reset it
    if (pos[node] == 1) 
        cat_count++;
    else 
        cat_count = 0;

    // If we exceed m consecutive cats, return
    if (cat_count > m) 
        return;

    bool isLeaf = true;
    for (int neigh : adj[node]) {
        if (!vis[neigh]) {
            isLeaf = false;
            dfs(neigh, cat_count, m, adj, vis, pos);
        }
    }

    // If it's a leaf and we reached here, count it
    if (isLeaf) 
        result++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> pos(n + 1); // Cat presence array
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }

    // Graph representation
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    dfs(1, 0, m, adj, vis, pos);

    cout << result << "\n";
    return 0;
}
