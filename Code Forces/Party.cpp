// This approaches more on the trees and traversing in the graph(bfs/dfs)
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
//  Quick Rule of Thumb
//  If the problem involves relationships (who reports to whom) → Think Graphs.
//  If the goal is to find the longest/shortest connection → Think DFS/BFS.
//  If there are dependencies in execution → Think Topological Sort.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int graph[n+1];
    for(int i=1;i<=n;i++){
        cin>>graph[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int node=graph[i];
        int dep=1;
        while(node!=-1){
            node=graph[node];
            dep++;
        }
        ans=max(ans,dep);
    }
    cout<<ans;


    return 0;
}