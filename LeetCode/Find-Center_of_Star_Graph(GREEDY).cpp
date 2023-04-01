class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (edges[i][j] == edges[i + 1][j])
                {
                    return edges[i + 1][j];
                }
                else if (edges[i][j + 1] == edges[i + 1][j + 1])
                {
                    return edges[i + 1][j + 1];
                }
                else if (edges[i][j + 1] == edges[i + 1][j])
                {
                    return edges[i + 1][j];
                }
                else if (edges[i][j] == edges[i + 1][j + 1])
                {
                    return edges[i + 1][j + 1];
                }
            }
        }
        return -1;
    }
};