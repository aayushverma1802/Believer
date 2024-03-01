
class Solution
{
    int f(int ind, int k, vector<int> &arr, vector<int> &dp)
    {
        int n = arr.size();
        if (ind == n)
            return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        if (dp[ind] != -1)
            return dp[ind];
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + f(j + 1, k, arr, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, arr, dp);
    }
};
