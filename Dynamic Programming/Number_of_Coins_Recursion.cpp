//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minCoins(int coins[], int M, int x)
    {
        // Your code goes here
        if (x == 0)
        {
            return 0;
        }
        if (x < 0)
        {
            return INT_MAX;
        }
        int mini = INT_MAX;
        for (int i = 0; i < M; i++)
        {
            int ans = minCoins(coins, M, x - coins[i]);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        if (mini == INT_MAX)
        {
            return -1;
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends