class Solution
{
public:
    int solve(vector<int> &prices, int n, int index, int buy, vector<vector<vector<int>>> &dp, int limit)
    {
        if (index == n)
        {
            return 0;
        }
        if (dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit];
        }
        if (limit == 0)
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[index] + solve(prices, n, index + 1, 0, dp, limit);
            int skipkaro = 0 + solve(prices, n, index + 1, 1, dp, limit);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[index] + solve(prices, n, index + 1, 1, dp, limit - 1);
            int skipkaro = 0 + solve(prices, n, index + 1, 0, dp, limit);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, n, 0, 1, dp, 2);
    }
};