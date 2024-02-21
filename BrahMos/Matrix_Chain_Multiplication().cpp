#include<vector>
int solve(int *arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=1e9;
    for(int k=i;k<j;k++){
        int ans=arr[k]*arr[i-1]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
        mini=min(ans,mini);
    }
    return dp[i][j]=mini;

}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(arr,1,n,dp);
}