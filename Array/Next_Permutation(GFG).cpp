//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> a)
    {
        // code here
        int idx = -1;

        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] > a[i - 1])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            reverse(a.begin(), a.end());
        }
        else
        {
            int prev = idx;
            for (int i = idx + 1; i < n; i++)
            {
                if (a[i] > a[idx - 1] and a[i] <= a[prev])
                {
                    prev = i;
                }
            }
            swap(a[idx - 1], a[prev]);
            reverse(a.begin() + idx, a.end());
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends