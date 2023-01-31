//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
// define modd 1000000007
class Solution
{
public:
    long mod = 1e9 + 7;
    int add(int a, int b)
    {
        return (a % mod + b % mod) % mod;
    }
    int mul(int a, int b)
    {
        return ((a % mod) * (b % mod)) % mod;
    }
    int solve(int n, int k)
    {
        // base case
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return add(k, mul(k, k - 1));
        }
        int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
        return ans;
    }
    int solve2(int n, int k, vector<int> &dp)
    {
        // base case
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return add(k, mul(k, k - 1));
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = add(mul(solve2(n - 2, k, dp), k - 1), mul(solve2(n - 1, k, dp), k - 1));
        return dp[n];
    }
    long long countWays(int n, int k)
    {
        // code here
        // Recursion
        // return solve(n,k);
        // Recursion+Memorization
        vector<int> dp(n + 1, -1);
        return solve2(n, k, dp);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends