class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        int min_So_far=prices[0];
        for( int i=0;i<n;i++){
            min_So_far=min(min_So_far,prices[i]);
            int profit=prices[i]-min_So_far;
            max_profit=max(max_profit,profit);
        }
        return max_profit;
    }
};