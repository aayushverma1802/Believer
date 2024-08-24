#include <bits/stdc++.h> 
int solve(vector<int> &weight, vector<int> &value, int n, int W, vector<vector<int>> &dp) 
{
    if (n == 0)
    {
        if (weight[0] <= W)
        {
            return value[0]; 
        }
        else
        {
            return 0;
        }
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    int take = 0;
    // for(int i=0;i<weight.size();i++){
    if (weight[n] <= W)
    {
        take = value[n] + solve(weight, value, n - 1, W - weight[n], dp);
    }

    // }
    int exclude = 0 + solve(weight, value, n - 1, W, dp);
    return dp[n][W] = max(exclude, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}
