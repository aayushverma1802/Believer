// Conditions to figure out digit_DP
// 1)Range will be given L-R
// 2)Conditions
// 3)It will have alot of constraints

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[20][2][20]; // index,flag,count
int solve(string &s, int idx, int flag, int cnt)
{
    if (idx == s.size())
    {
        return cnt;
    }
    if (dp[idx][flag][cnt] != -1)
    {
        return dp[idx][flag][cnt];
    }
    int ans = 0;
    int limit = (flag == 1 ? s[idx] - '0' : 9);
    for (int i = 0; i <= limit; i++)
    {
        int updateCnt = cnt + (i == 3 ? 1 : 0);
        ans += solve(s, idx + 1, (flag and (i == s[idx] - '0')), updateCnt);
    }
    return dp[idx][flag][cnt] = ans;
}
int main()
{
    int l, r;
    cin >> l >> r;
    string ri = to_string(r);
    memset(dp, -1, sizeof(dp)); // Reset DP for fresh computation
    int rightAns = solve(ri, 0, 1, 0);
    memset(dp, -1, sizeof(dp)); // Reset DP for fresh computation
    string le = to_string(l - 1);
    int leftAns = solve(le, 0, 1, 0);
    cout << rightAns - leftAns << endl;
    return 0;
}