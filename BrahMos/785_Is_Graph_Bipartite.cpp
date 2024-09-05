class Solution
{
public:
    bool bfs(int i, int n, vector<vector<int>> &graph, vector<int> &color)
    {
        color[i] = 0;
        queue<int> q;

        q.push(i);
        while (q.empty() == false)
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, n, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};