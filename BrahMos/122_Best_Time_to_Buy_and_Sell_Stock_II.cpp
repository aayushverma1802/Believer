class Solution
{
public:
    int solve(vector<int> &prices, int n, int index, int buy, vector<vector<int>> &dp)
    {
        if (index == n)
        {
            return 0;
        }
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[index] + solve(prices, n, index + 1, 0, dp);
            int skipkaro = 0 + solve(prices, n, index + 1, 1, dp);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[index] + solve(prices, n, index + 1, 1, dp);
            int skipkaro = 0 + solve(prices, n, index + 1, 0, dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(prices, n, 0, 1, dp);
    }
};