class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int maxProfit = 0;
        int minSofar = prices[0];
        for (int i = 1; i < n; i++)
        {
            profit = prices[i] - minSofar;
            maxProfit = max(profit, maxProfit);
            minSofar = min(prices[i], minSofar);
        }
        return maxProfit;
    }
};