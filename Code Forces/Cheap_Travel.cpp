#include <iostream>
#include<utility>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int sum = 0;
    //     What Do the Variables Represent?
    // n: Number of rides Ann needs.

    // m: Number of rides covered by a special ticket.

    // a: Cost of a single ride ticket.

    // b: Cost of an m-ride special ticket.
    if (m*a<=b){
        cout<<n*a;
    }
    else{
        cout<<(n/m)*b+min(n%m*a,b);
    }
      
    return 0;
}