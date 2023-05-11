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
    int findCircleNum(vector<vector<int>> &adj)
    {
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