//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int weight[], int value[], int index, int W)
    {
        // Base Case
        // if only 1 item to steal , then just compare its weight with the knapsack capacity
        if (index == 0)
        {
            if (weight[0] <= W)
            {
                return value[0];
            }
            else
            {
                return 0;
            }
        }
        int include = 0;
        if (weight[index] <= W)
        {
            include = value[index] + solve(weight, value, index - 1, W - weight[index]);
        }
        int exclude = 0 + solve(weight, value, index - 1, W);
        int ans = max(include, exclude);
        return ans;
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        return solve(wt, val, n - 1, W);
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