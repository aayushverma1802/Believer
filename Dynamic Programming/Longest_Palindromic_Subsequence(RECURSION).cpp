//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(string &s, string &b, int i, int j)
    {
        if (i == s.length())
        {
            return 0;
        }
        if (j == b.length())
        {
            return 0;
        }

        //  string ans="";
        if (s[i] == b[j])
        {
            return 1 + solve(s, b, i + 1, j + 1);
        }
        int s1 = solve(s, b, i, j + 1);
        int s2 = solve(s, b, i + 1, j);
        return max(s1, s2);
    }

    int longestPalinSubseq(string A)
    {
        // code here
        string t = A;
        reverse(t.begin(), t.end());
        return solve(A, t, 0, 0);
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