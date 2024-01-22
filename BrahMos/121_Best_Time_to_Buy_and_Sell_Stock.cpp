class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        int minsofar = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - minsofar;
            maxprofit = max(maxprofit, profit);
            minsofar = min(minsofar, prices[i]);
        }
        return maxprofit;
    }
};