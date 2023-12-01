class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int limit)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (limit == 0)
        {
            return 0;
        }
        if (dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit];
        }
        int profit = 0;

        if (buy)
        {
            int buykaro = -prices[index] + solve(index + 1, 0, prices, dp, limit);
            int skipkaro = 0 + solve(index + 1, 1, prices, dp, limit);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[index] + solve(index + 1, 1, prices, dp, limit - 1);
            int skipkaro = 0 + solve(index + 1, 0, prices, dp, limit);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy][limit] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices, dp, 2);
    }
};