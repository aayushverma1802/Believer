class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, pair<int, int>>> q; // {steps, {row, col}}
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int nrow[4] = {-1, 1, 0, 0};
        int ncol[4] = {0, 0, -1, 1};

        int startRow = entrance[0], startCol = entrance[1];
        q.push({0, {startRow, startCol}});
        vis[startRow][startCol] = true;

        while (!q.empty())
        {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int irow = row + nrow[i];
                int icol = col + ncol[i];
                if (irow >= 0 && irow < n && icol >= 0 && icol < m &&
                    maze[irow][icol] == '.' && !vis[irow][icol])
                {
                    if (irow == 0 || irow == n - 1 || icol == 0 || icol == m - 1)
                    {
                        return steps + 1;
                    }
                    vis[irow][icol] = true;
                    q.push({steps + 1, {irow, icol}});
                }
            }
        }

        return -1;
    }
};
