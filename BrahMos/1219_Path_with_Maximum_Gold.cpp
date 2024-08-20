class Solution
{
public:
    int n = 0, m = 0;

    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j])
        {
            return 0;
        }

        visited[i][j] = true; // Mark the cell as visited

        // Explore all four directions and get the maximum gold
        int maxGold = 0;
        maxGold = max(maxGold, dfs(i + 1, j, grid, visited)); // Down
        maxGold = max(maxGold, dfs(i - 1, j, grid, visited)); // Up
        maxGold = max(maxGold, dfs(i, j + 1, grid, visited)); // Right
        maxGold = max(maxGold, dfs(i, j - 1, grid, visited)); // Left

        visited[i][j] = false; // Backtrack by unmarking the cell
        return grid[i][j] + maxGold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int maxGold = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Create a 2D visited vector

        // Iterate over each cell in the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    maxGold = max(maxGold, dfs(i, j, grid, visited));
                }
            }
        }

        return maxGold;
    }
};
