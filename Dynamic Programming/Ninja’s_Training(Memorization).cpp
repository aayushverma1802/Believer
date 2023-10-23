#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &v, int l, int n, vector<vector<int>> &dp)
{
    if (dp[n][l] != -1)
    {
        return dp[n][l];
    }

    if (n == 0)
    {
        int maxi = 0;
        for (int i = 0; i <= 2; i++)
        {
            if (i != l)
            {
                // int ans =
                maxi = max(v[0][i], maxi);
            }
        }
        return dp[n][l] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
        if (i != l)
        {
            int ans = v[n][i] + solve(v, i, n - 1, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[n][l] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, 3, n - 1, dp);
}