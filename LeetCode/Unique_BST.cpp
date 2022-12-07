class Solution {
public:
    int solve(int n){
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            //number of nodes
            for(int j=1;j<=i;j++){
                //number of root nodes
                dp[i]+=dp[j-1]*dp[i-j];
                
            
            }
            
        }
        return dp[n];
    }
    int numTrees(int n) 
    {
        // Your code here

        return solve(n);
    }
};