//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    stack<int> s;
    vector<int> ans;

    vector<int> leftSmaller(int n, int a[])
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            while (s.empty() == false and (a[i] <= s.top()))
            {
                s.pop();
                //
            }
            if (s.empty() == true)
            {

                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(a[i]);
        }
        return ans;
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
        vector<int> ans = ob.leftSmaller(n, a);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends