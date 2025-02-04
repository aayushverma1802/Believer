// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    // If the n is big then we - 1 the n to match to m
    // So this one is the easy approach

    // We should take care when it comes to n smaller then m
    // Infinite steps can take place.
    int count = 0;

    if (n >= m)
    {
        cout << n - m;
    }
    else
    {

        // We are doing backtracking here with a little mathematical logic
        while (m > n)
        {
            if (m % 2 == 0)
            {
                m /= 2;
                count++;
            }
            else
            {
                m += 1;
                count++;
            }
        }
        cout << (n - m) + count << endl;
    }

    return 0;
}