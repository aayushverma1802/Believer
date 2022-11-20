//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int a,int b){
               if(M[a][b]==1){
                   return true;
               }
               else{ return false;}
        
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {

        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
            
        }
        while(s.size()>1){
            int a =s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        int cand=s.top();
            for (int i=0;i<n;i++){
            if (i!=cand && (knows(M,i,cand)==false || knows(M,cand,i)==true)){
                return -1;
            }
        }
        return cand;

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends