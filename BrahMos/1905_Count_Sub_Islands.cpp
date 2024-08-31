class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid1,
             vector<vector<int>> &grid2, vector<vector<int>> &vis, int n, int m, bool &isSubIsland)
    {
        vis[i][j] = true;

        if (grid1[i][j] == 0)
        {
            isSubIsland = false; // Not a sub-island if this part is not in grid1
        }

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int rval = i + row[k];
            int cval = j + col[k];

            if (rval >= 0 && rval < n && cval >= 0 && cval < m && !vis[rval][cval] && grid2[rval][cval] == 1)
            {
                dfs(rval, cval, grid1, grid2, vis, n, m, isSubIsland);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        int n = grid1.size();
        int m = grid2[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid2[i][j] == 1 && !vis[i][j])
                {
                    bool isSubIsland = true;
                    dfs(i, j, grid1, grid2, vis, n, m, isSubIsland);
                    if (isSubIsland)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
