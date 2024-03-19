class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        // Check for top,right,bottom,left;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and
                mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // traverse the first and the last row

        for (int j = 0; j < m; j++)
        {
            // first row
            if (!vis[0][j] and board[0][j] == 'O')
            {
                dfs(0, j, vis, board, delrow, delcol);
            }
            if (!vis[n - 1][j] and board[n - 1][j] == 'O')
            {
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++)
        {
            // first column
            if (!vis[i][0] and board[i][0] == 'O')
            {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if (!vis[i][m - 1] and board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        // return board;
    }
};