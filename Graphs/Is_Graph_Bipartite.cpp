class Solution
{
public:
    bool check(int start, int V, vector<vector<int>> &graph, int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                // if the adj node is yet not colored
                // you will give the opposite color of the node
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adj guy having the same color
                // someone did color it on some other path
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
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, V, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};