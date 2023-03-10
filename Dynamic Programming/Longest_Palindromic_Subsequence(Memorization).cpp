//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(string &s, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s.length())
        {
            return 0;
        }
        if (j == b.length())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        //  string ans="";
        if (s[i] == b[j])
        {
            return dp[i][j] = 1 + solve(s, b, i + 1, j + 1, dp);
        }
        int s1 = solve(s, b, i, j + 1, dp);
        int s2 = solve(s, b, i + 1, j, dp);
        return dp[i][j] = max(s1, s2);
    }

    int longestPalinSubseq(string A)
    {
        // code here
        string t = A;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(A.length(), vector<int>(A.length(), -1));
        return solve(A, t, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends