//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }
        if (i == 0)
        {
            return sum == arr[i];
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        // Now i have to cases to make my problem solve
        // First i will take the number
        // Second i will not take the number in the array
        bool take = false;
        bool not_Take = false;
        if (sum >= arr[i])
        {
            take = solve(arr, sum - arr[i], i - 1, dp);
        }
        not_Take = solve(arr, sum, i - 1, dp);
        return dp[i][sum] = take or not_Take;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, sum, n - 1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Endss