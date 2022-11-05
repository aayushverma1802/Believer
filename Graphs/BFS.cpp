#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+2;
bool vis[N];
vector<int>adj[N];


int main(){
    //Enter the nodes and the edges 
    //n->nodes;
    //m->edges;
    for(int i=0;i<N;i++){
        //Initializing all the elements as 0;
        vis[N]=0;        
    }
    int n,m;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int >q;
    q.push(1);
    vis[1]=true;
    while(q.empty()==false){
        int node =q.front();
        q.pop();
        cout<<node<<endl;
        vector<int>:: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    
    
}

/*Sample Test Cases;


Enter the number of nodes
7
Enter the number of edges
7
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
3
4
5
6
7
*/
