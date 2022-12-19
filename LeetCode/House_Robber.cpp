class Solution {
public:
    int solve(vector <int> &kp,int n,vector<int>&dp)
{
    if(n<0){
        return 0;
    }
    if(n==0){
        return kp[n];   
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int incl=solve(kp,n-2,dp)+kp[n];
    int excl=solve(kp,n-1,dp);
    return dp[n]=max(incl,excl);
}
        int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }

};