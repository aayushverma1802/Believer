//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    int solve(int kp[], int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return kp[n];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int incl = solve(kp, n - 2, dp) + kp[n];
        int excl = solve(kp, n - 1, dp);
        return dp[n] = max(incl, excl);
    }
    int FindMaxSum(int nums[], int n)
    {
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n, -1);
        return solve(nums, n - 1, dp);
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
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends