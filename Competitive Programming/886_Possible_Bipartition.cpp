class Solution
{
public: 
    bool bip(int n, vector<vector<int>> &adj, int node, vector<int> &color)
    {

        for (auto i : adj[node])
        {
            if (color[i] == -1)
            { 
                color[i] = !color[node];
                if (!bip(n, adj, i, color))
                    return false;
            }
            else if (color[i] == color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &pair : dislikes)
        {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        vector<int> color(n + 1, -1);
        for (int i = 1; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (bip(n, adj, i, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};