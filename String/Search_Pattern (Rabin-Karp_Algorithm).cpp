//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
int p = 31;
const int N = 1e5, m = 1e9;
vector<long long> power(N);
class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // code here.
        string s = pat;
        string t = txt;
        int T = t.size();
        int S = s.size();
        power[0] = 1;
        for (int i = 1; i < N; i++)
        {
            power[i] = (power[i - 1] * p) % m;
        }
        vector<long long> h(T + 1, 0);
        for (int i = 0; i < T; i++)
        {
            h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
        }
        long long h_s = 0;
        for (int i = 0; i < S; i++)
        {
            h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % m;
        }
        vector<int> ans;
        for (int i = 0; i + S - 1 < T; i++)
        {
            long long curr_h = (h[i + S] - h[i] + m) % m;
            if (curr_h == (h_s * power[i]) % m)
            {
                ans.push_back(i + 1);
            }
        }
        if (ans.size() > 0)
        {
            return ans;
        }
        return {-1};
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
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends