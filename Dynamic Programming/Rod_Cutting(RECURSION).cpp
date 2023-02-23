//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int ind, int n, int price[])
    {
        if (ind == 0)
        {
            return n * price[0];
        }
        int take = INT_MIN;
        int rodLength = ind + 1;

        if (rodLength <= n)
        {
            take = price[ind] + solve(ind, n - rodLength, price);
        }
        int notTake = 0 + solve(ind - 1, n, price);
        return max(take, notTake);
    }
    int cutRod(int price[], int n)
    {
        // code here
        return solve(n - 1, n, price);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends