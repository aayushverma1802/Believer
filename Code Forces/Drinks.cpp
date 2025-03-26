#include <iostream>
using namespace std;
int main()
{
    double n;
    cin >> n;
    double k = n;
    double sum=0;
    while (n--)
    {
        double p;
        cin >> p;
        sum += p;
    }
    cout <<(long double) sum / k;
    return 0;
}