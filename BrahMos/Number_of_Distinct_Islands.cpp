// User function Template for C++

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
    {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = dcol[i] + col;
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<pair<int, int>> vec;
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};