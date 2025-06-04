class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &piles, int k, int n)
    {
        if (k == 0 || n < 0)
            return 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        int not_take = solve(piles, k, n - 1);
        int max_val = not_take;
        int curr = 0;

        for (int i = 0; i < min(k, (int)piles[n].size()); i++)
        {
            curr += piles[n][i];
            int take = curr + solve(piles, k - i - 1, n - 1);
            max_val = max(max_val, take);
        }

        return dp[n][k] = max_val;
    }

    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));
        return solve(piles, k, n - 1);
    }
};
