//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
    bool isT(vector<int> &cc)
    {
        for (auto &i : cc)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt)
    {
        // code here
        int n = txt.size();
        int k = pat.size();
        vector<int> cc(26, 0);
        for (int i = 0; i < k; i++)
        {
            char v = pat[i];
            cc[v - 'a']++;
        }
        int ans = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            cc[txt[j] - 'a']--;
            if (j - i + 1 == k)
            {
                if (isT(cc))
                {
                    ans++;
                }

                cc[txt[i] - 'a']++;
                i++;
            }
            j++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends