/*
Limitation:-
Works Only for small input.
*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e7;
vector<int> dp(N, -1);
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n) ;
    return 69;
}
