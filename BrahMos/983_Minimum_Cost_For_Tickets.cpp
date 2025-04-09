class Solution
{
public:
    int solve(vector<int> &days, vector<int> &costs, int n, vector<int> &go_days, vector<int> &dp)
    {
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int min_cost = INT_MAX;

        for (int i = 0; i < 3; i++)
        {
            int j = n;

            while (j >= 0 && days[n] - days[j] < go_days[i])
            {
                j--;
            }

            int cost = costs[i] + solve(days, costs, j, go_days, dp);
            min_cost = min(min_cost, cost);
        }

        return dp[n] = min_cost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> go_days = {1, 7, 30};
        vector<int> dp(n, -1);
        return solve(days, costs, n - 1, go_days, dp);
    }
};
