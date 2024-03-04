int solve(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)

{

    if (ind == 0)

    {

        return (W / weight[0]) * profit[0];
    }

    if (dp[ind][W] != -1)

        return dp[ind][W];

    int nottake = solve(ind - 1, W, profit, weight, dp);

    int take = 0;

    if (weight[ind] <= W)

        take = profit[ind] + solve(ind, W - weight[ind], profit, weight, dp);

    return dp[ind][W] = max(take, nottake);
}

// Tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}