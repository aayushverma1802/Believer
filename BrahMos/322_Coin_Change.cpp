class Solution
{
public:
    int solver(int ind, int target, vector<int> coins, vector<vector<int>> &dp)
    {
        // base case
        if (ind == 0)
        {
            if (target % coins[ind] == 0)
                return target / coins[ind];
            return 1e9;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        // not take coin
        int ntake = solver(ind - 1, target, coins, dp);
        // take coin
        int take = 1e9;
        if (coins[ind] <= target)
            take = 1 + solver(ind, target - coins[ind], coins, dp);
        return dp[ind][target] = min(take, ntake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int sol = solver(n - 1, amount, coins, dp);
        if (sol >= 1e9)
            return -1;
        return sol;
    }
};