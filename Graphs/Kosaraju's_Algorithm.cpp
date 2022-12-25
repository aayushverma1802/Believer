//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<bool>&vis,stack<int>&st ,vector<int>adj[]){
	    vis[node]=true;
	    for(auto nbr: adj[node]){
	        if(!vis[nbr]){
	            dfs(nbr,vis,st,adj);
	        }
	        
	    }
	    //topological sort logic4
	    st.push(node);
	}
	void rev_dfs(int node,vector<bool>&vis,vector<int>adj[]){
	    vis[node]=true;
	    for(auto nbr:adj[node]){
	        if(!vis[nbr]){
	            rev_dfs(nbr,vis,adj);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        
        //Topological Sort
        stack <int>st;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        //create a transpose graph
        vector<int>transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=false;
            for(auto nbr: adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        //dfs call using above ordering
        int count=0; 
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!vis[top]){
                count++;
                rev_dfs(top,vis,transpose);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends