//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(string &s1, string &s2, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return 0;
        }
        if (j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            int ans = 1 + solve(s1, s2, i - 1, j - 1, maxi, dp);
            maxi = max(maxi, ans);
            dp[i][j] = ans;
            return ans;
        }
        solve(s1, s2, i - 1, j, maxi, dp);
        solve(s1, s2, i, j - 1, maxi, dp);

        return dp[i][j] = 0;
    }
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        // your code here
        int maxi = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                solve(s1, s2, i, j, maxi, dp);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends