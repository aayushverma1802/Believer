#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int x = 0;
    int n = 0;
    cin >> n;
    string s = "";
    int ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s[0] == '+' or s[s.size() - 1] == '+')
        {
            ans++;
        }
        else if (s[0] == '-' or s[s.size() - 1] == '-')
        {
            ans--;
        }
    }
    cout << ans;
 
    return 0;
}