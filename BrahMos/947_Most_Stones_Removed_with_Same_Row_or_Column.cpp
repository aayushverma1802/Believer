class Solution
{
public:
    void dfs(vector<vector<int>> &stones, vector<bool> &vis, int node)
    {
        vis[node] = true;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!vis[i] && (stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1]))
            {
                dfs(stones, vis, i);
            }
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxi = INT_MIN;
        int connected_component = 0;
        vector<bool> vis(stones.size() + 1, false);
        for (int i = 0; i < stones.size(); i++)
        {
            if (vis[i] == false)
            {
                connected_component++;
                dfs(stones, vis, i);
            }
        }
        return n - connected_component;
    }
};