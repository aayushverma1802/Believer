#include <iostream>
using namespace std;
int main()
{

    string s;
    cin >> s;
    long long int q = 0, a = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'Q')
        {
            q++;
            ans += a;
        }
        else if (s[i] =='A')
        {
            a += q;
        }
    }
    cout << ans << endl;
    return 0;
}