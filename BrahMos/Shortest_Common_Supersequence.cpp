//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.
    int solve(string &x, string &y, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return j;
        }
        if (j < 0)
        {
            return i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int take = INT_MAX;
        int not_take = INT_MAX;
        if (x[i] == y[j])
        {
            return dp[i][j] = 1 + solve(x, y, i - 1, j - 1, dp);
        }
        return dp[i][j] = 1 + min(solve(x, y, i - 1, j, dp), solve(x, y, i, j - 1, dp));
        // return min(take,not_take);
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        vector<vector<int>> dp(X.size(), vector<int>(Y.size(), -1));
        return solve(X, Y, X.size() - 1, Y.size() - 1, dp) + 1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking total testcases
    cin >> t;
    while (t--)
    {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}

// } Driver Code Ends