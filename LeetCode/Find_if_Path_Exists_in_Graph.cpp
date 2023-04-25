class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr, int destination) {
        if (curr == destination) return true;
        visited[curr] = true;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, neighbor, destination)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(adj, visited, source, destination);
    }
};
