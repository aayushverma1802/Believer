#include <bits/stdc++.h> 
int solve(vector<int> &nums,int n,vector<int>&dp){
     //Base case
//     vector<int>dp(n,-1);
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];   
    }
    if(dp[n]!=-1){
        return dp[n];
        
    }
    
    int incl=solve(nums,n-2,dp)+nums[n];
    int excl=solve(nums,n-1,dp)+0;
    return dp[n]=max(incl,excl);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    int ans=solve(nums,n-1,dp);
    return ans;
    
    
}