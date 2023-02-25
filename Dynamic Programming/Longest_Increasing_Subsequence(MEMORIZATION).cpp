//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        // base case
        if (curr == n)
        {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        // include
        int take = 0;
        if (prev == -1 or a[curr] > a[prev])
        {
            take = 1 + solve(n, a, curr + 1, curr, dp);
        }
        // exclude
        int notTake = 0 + solve(n, a, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(take, notTake);
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, a, 0, -1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends