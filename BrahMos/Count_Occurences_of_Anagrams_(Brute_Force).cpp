//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int cnt=0;
        sort(begin(pat),end(pat));
        string check=pat;
        for(int i=0;i<=txt.size()-pat.size();i++){
            string cc=txt.substr(i,pat.size());
            sort(begin(cc),end(cc));
            if(cc==check)
                cnt++;
            
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
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