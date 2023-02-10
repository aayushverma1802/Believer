//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int weight[], int value[], int n, int capacity)
    {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        for (int w = weight[0]; w <= capacity; w++)
        {
            if (weight[0] <= capacity)
            {
                dp[0][w] = value[0];
            }
            else
            {
                dp[0][w] = 0;
            }
        }
        for (int index = 1; index < n; index++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                int include = 0;
                if (weight[index] <= w)
                {
                    include = value[index] + dp[index - 1][w - weight[index]];
                }
                int exclude = 0 + dp[index - 1][w];
                dp[index][w] = max(exclude, include);
            }
        }

        return dp[n - 1][capacity];
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return solve(wt, val, n, W);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends