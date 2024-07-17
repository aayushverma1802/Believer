class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int oldcolor, vector<vector<int>> &vis, int color)
    {
        if (sr < 0 or sc < 0 or sc >= image[0].size() or sr >= image.size())
        {
            return;
        }
        if (vis[sr][sc] == true or image[sr][sc] != oldcolor)
        {
            return;
        }
        vis[sr][sc] = true;
        image[sr][sc] = color;

        dfs(image, sr + 1, sc, oldcolor, vis, color);
        dfs(image, sr, sc - 1, oldcolor, vis, color);
        dfs(image, sr - 1, sc, oldcolor, vis, color);
        dfs(image, sr, sc + 1, oldcolor, vis, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, false));
        dfs(image, sr, sc, oldcolor, vis, color);
        return image;
    }
};