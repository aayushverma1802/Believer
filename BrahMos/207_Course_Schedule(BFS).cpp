class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &pp)
    {
        int V = numCourses;
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> adj[V];
        for (auto it : pp)
        {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (q.empty() == false)
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto i : adj[node])
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if (ans.size() == V)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};