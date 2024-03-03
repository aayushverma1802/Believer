class Solution {
public:
int solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
    if(i==nums.size()){
        if(target==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][target+2000]!=-1){
        return dp[i][target+2000];
    }
    int add=solve(i+1,nums,target+nums[i],dp);
    int sub=solve(i+1,nums,target-nums[i],dp);
    return dp[i][target+2000]=add+sub;
    
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(5005,-1));
        return solve(0,nums,target,dp );   
    }
};