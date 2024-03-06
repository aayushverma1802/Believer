#include <vector>
int solve(vector<int> &price, int n, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return n * price[0];
    }
    if (dp[ind][n] != -1)
    {
        return dp[ind][n];
    }
    int notTake = 0 + solve(price, n, ind - 1, dp);
    int Take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= n)
    {
        Take = price[ind] + solve(price, n - rodLength, ind, dp);
    }
    return dp[ind][n] = max(Take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(price, n, n - 1, dp);
}
