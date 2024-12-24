#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n, m;
        cin >> n >> m;
        int count = 0;
        // row is odd and col is even;
        if (m % 2 == 0)
        {
            count = n * (m / 2);
        }
        // row is even and col is odd;
        else if (n % 2 == 0)
        {
            count = (n / 2) * m;
        }
        // the last stage ;
        // row and col both are odd;
        else
        {
            count = n*(m/2)+n/2+1;
        }
        cout<<count<<endl;
        t--;
    }
    return 0;
}