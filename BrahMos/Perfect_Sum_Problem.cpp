//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int mod = 1e9 + 7;
    int solve(int i, int arr[], int sum, vector<vector<int>> &dp, int n)
    {
        if (i == n - 1)
        {
            if (sum == 0 and arr[n - 1] == 0)
                return 2;
            if (sum == 0 or arr[n - 1] == sum)
                return 1;
            return 0;
        }
        // if(sum<0)return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int take = 0;
        if (arr[i] <= sum)
            take = solve(i + 1, arr, sum - arr[i], dp, n);
        int ntake = solve(i + 1, arr, sum, dp, n);
        return dp[i][sum] = (take + ntake) % mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(0, arr, sum, dp, n);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends