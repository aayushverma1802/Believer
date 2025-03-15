#include <iostream>
#include <math.h>
using ll=long long int;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, a;
    cin >> n >> m >> a;
    cout << ((n+a-1)/ a) * ((m+a-1) / a);

    return 0;
}