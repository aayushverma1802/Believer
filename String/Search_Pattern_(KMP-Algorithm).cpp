//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // code hee.
        vector<int> ans;
        int n = txt.length();
        int m = pat.length();
        // 1) making lps array
        vector<int> lps(m);
        int len = 0;
        int i = 1;
        while (i < m)
        {
            // if equal
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            // not equal
            else
            {
                if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }

        int s1 = 0; // txt
        int s2 = 0; // pat
        while (s1 < n)
        {
            if (txt[s1] == pat[s2])
            {
                s1++;
                s2++;
            }
            if (s2 == m)
            {
                ans.push_back(s1 - m + 1);
                s2 = lps[s2 - 1];
            }
            else if (s1 < n and pat[s2] != txt[s1])
            {
                if (s2 == 0)
                {
                    s1++;
                }
                else
                {
                    s2 = lps[s2 - 1];
                }
            }
        }
        if (ans.size() == 0)
            return {-1};
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends