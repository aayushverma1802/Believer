#include <iostream>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
 
    if (n == 2 || n & 1) // If n is 2 or an odd number
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
 
    return 0;
}