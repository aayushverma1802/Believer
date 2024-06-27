class Solution {
public:

int cnt=0;
void dfs(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<int>>& vis){
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or vis[i][j]){
        return;
    }
    vis[i][j]=1;
    // dfs()
         dfs(grid, i + 1, j,n,m,vis);
        dfs(grid, i - 1, j,n,m,vis);
        dfs(grid, i, j + 1,n,m,vis);
        dfs(grid, i, j - 1,n,m,vis);
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==0){
                cnt++;
                dfs(grid,i,j,n,m,vis);
                }

            }
        }
        return cnt ;
    }
};