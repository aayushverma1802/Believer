//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int n, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (wt[0] <= w)
            {
                return w / wt[0] * val[0];
            }
            else
            {
                return 0;
            }
        }

        if (dp[n][w] != -1)
        {
            return dp[n][w];
        }

        int not_take = solve(n - 1, w, val, wt, dp);
        int take = 0;
        if (wt[n] <= w)
        {
            take = val[n] + solve(n, w - wt[n], val, wt, dp);
        }

        return dp[n][w] = max(take, not_take);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return solve(N - 1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends