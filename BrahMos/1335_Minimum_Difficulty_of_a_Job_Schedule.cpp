class Solution
{
public:
    int solve(vector<int> &jobD, int d, int n, vector<vector<int>> &dp)
    {
        // Base Case: If all jobs are completed and days are finished
        if (n == 0 && d == 0)
            return 0;

        // If jobs are finished but days are remaining, return invalid case
        if (n == 0 || d == 0)
            return INT_MAX;

        int maxi = 0;
        int minDifficulty = INT_MAX;
        if (dp[n][d] != -1)
        {
            return dp[n][d];
        }
        // Track maximum job difficulty of the current partition
        for (int i = n - 1; i >= 0; i--)
        {
            maxi = max(maxi, jobD[i]); // Find max job difficulty in the current partition
            int next_days = solve(jobD, d - 1, i, dp);
            if (next_days != INT_MAX)
            { // If valid partition
                minDifficulty = min(minDifficulty, maxi + next_days);
            }
        }

        return dp[n][d] = minDifficulty;
    }

    int minDifficulty(vector<int> &jobD, int d)
    {
        int n = jobD.size();
        if (d > n)
            return -1;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        return solve(jobD, d, n, dp);
    }
};