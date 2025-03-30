class Solution
{
public:
    void dfs(vector<vector<int>> &rooms, int node, vector<bool> &vis)
    {
        vis[node] = true;
        for (auto &i : rooms[node])
        {
            if (vis[i] == false)
            {
                dfs(rooms, i, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for (auto i : vis)
        {
            if (i == false)
            {
                return false;
            }
        }
        return true;
    }
};