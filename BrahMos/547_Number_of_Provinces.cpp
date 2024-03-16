class Solution
{
public:
    void dfs(int i, vector<int> adj[], vector<bool> &vis)
    {
        vis[i] = true;
        for (auto k : adj[i])
        {
            if (vis[k] == false)
            {
                dfs(k, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // make an adjoint matrix
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};