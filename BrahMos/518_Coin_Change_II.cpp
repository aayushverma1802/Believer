class Solution
{
private:
    int solve(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(ind - 1, target, coins, dp);
        int take = 0;
        if (coins[ind] <= target)
        {
            take = solve(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = notTake + take;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);

        return ans;
    }
};