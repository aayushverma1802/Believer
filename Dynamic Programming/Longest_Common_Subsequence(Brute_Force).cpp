//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int solve(string &a, string &b, int i, int j)
    {
        if (i == a.length())
        {
            return 0;
        }
        if (j == b.length())
        {
            return 0;
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solve(a, b, i + 1, j + 1);
        }
        else
        {
            ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
        }
        return ans;
    }
    int lcs(int x, int y, string text1, string text2)
    {
        // your code here
        return solve(text1, text2, 0, 0);
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends