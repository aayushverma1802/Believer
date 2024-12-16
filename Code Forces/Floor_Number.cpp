#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; // Floor
        int x; // Rooms
        cin >> n >> x;
        if (n <= 2)
        {
            cout << 1 << endl; // It has to be on the first floor
        }
        else
        {
            n -= 2;
            int res = ceil((double)n / x);
            cout << res + 1 << endl;
        }
    }

    return 0;
}