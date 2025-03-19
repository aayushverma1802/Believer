class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid) 
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        // int vis[n][m]={0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        while (q.empty() == false)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and
                    grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
