//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define MOD 1000000007
class Solution
{
public:
    long long int solve(int n, vector<long long int> &dp)
    {
        if (n == 1 or n == 2)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = (solve(n - 1, dp) % MOD + ((n - 1) * solve(n - 2, dp) % MOD) % MOD) % MOD;
        // return
    }
    int countFriendsPairings(int n)
    {
        // code here
        // f(n)=f(n-1)+(n-1)*f(n-2);
        vector<long long int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// } Driver Code Ends