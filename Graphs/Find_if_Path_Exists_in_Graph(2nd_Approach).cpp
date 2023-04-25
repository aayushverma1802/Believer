class Solution {
public:
 
    void dfs(int n,vector<int>adj[n],vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(n,adj,vis,it);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(n,adj,vis,source);
        if(vis[source]==1 and vis[destination]==1)
        return true;
        else
        return false;
    }
};
