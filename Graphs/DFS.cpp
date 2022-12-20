#include <iostream>
#include <vector>
#include<queue>
using namespace std;
const int N = 1e7;
vector<int> adj[N];
bool vis[N];
void dfs (int node){
    vis[node]=true;
    cout<<node<<endl;
    for(auto it:adj[node]){
        if(vis[it]==false){

            dfs(it);
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    //Enter the number of nodes and edges
    for(int i=0;i<N;i++){
        vis[i]=false;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //Enter the u and v nodes;
        adj[u].push_back(v);
        //This is the undirected graph
        adj[v].push_back(u);
    }
    dfs(1);


}

/*
Input
7 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3


Output
1
2
4
5
6
7
3

*/