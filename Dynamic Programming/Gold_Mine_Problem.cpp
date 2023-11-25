//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &M, int m, int n, vector<vector<int>> &dp)
    {
        if (i < 0 or j >= m or i >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int digup = M[i][j] + solve(i - 1, j + 1, M, m, n, dp);
        int digdown = M[i][j] + solve(i + 1, j + 1, M, m, n, dp);
        int right = M[i][j] + solve(i, j + 1, M, m, n, dp);
        return dp[i][j] = max(digup, (max(digdown, right)));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxi = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int row = 0; row < n; row++)
        {
            int ans = solve(row, 0, M, m, n, dp);
            maxi = max(ans, maxi);
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}
// } Driver Code Ends