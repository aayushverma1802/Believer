#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long int dp[20][2][4];

long long int solve(string &s, long long int index, long long int flag, long long int count)
{
    if (index == s.size())
        return 1;

    if (dp[index][flag][count] != -1)
        return dp[index][flag][count];

    long long int ans = 0;
    long long int limit = (flag == 1 ? s[index] - '0' : 9);

    for (long long int i = 0; i <= limit; i++)
    {
        long long int updateCnt = count + (i != 0 ? 1 : 0);

        if (updateCnt <= 3)
        {
            ans += solve(s, index + 1, (flag & (i == s[index] - '0')), updateCnt);
        }
    }

    return dp[index][flag][count] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;

    while (n--)
    {
        long long int l, r;
        cin >> l >> r;

        string ri = to_string(r);
        memset(dp, -1, sizeof(dp));

        long long int rightAns = solve(ri, 0, 1, 0);

        string le = to_string(l - 1);
        memset(dp, -1, sizeof(dp));

        long long int leftAns = solve(le, 0, 1, 0);

        cout << rightAns - leftAns << endl;
    }

    return 0;
}
