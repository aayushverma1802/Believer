
int solve(vector<vector<int>> &p, int day, int last, vector<vector<int>> &dp)
{
    // Base case
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, p[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            dp[day][last] = maxi = max(p[day][i] + solve(p, day - 1, i, dp), maxi);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(points, n - 1, 3, dp);
}