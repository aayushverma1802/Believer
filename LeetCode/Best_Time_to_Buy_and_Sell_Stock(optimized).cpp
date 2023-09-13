class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int maxprofit = 0;
        int minSoFar = prices[0];
        for (int i = 0; i < n; i++)
        {
            profit = prices[i] - minSoFar;
            maxprofit = max(profit, maxprofit);
            minSoFar = min(minSoFar, prices[i]);
        }
        return maxprofit;
    }
};