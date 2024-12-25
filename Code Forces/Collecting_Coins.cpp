#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        if (sum % 3 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            if (a > sum / 3 or b > sum / 3 or c > sum / 3)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        t--;
    }

    return 0;
}