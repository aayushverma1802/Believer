#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
// #include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> vec(3, 0);
    for (int i = 0; i < t; i++)
    {
        cin >> vec[0] >> vec[1] >> vec[2];

        sort(all(vec));
        if (vec[1] != vec[2])
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << vec[0] << " " << vec[2] << " " << vec[0] << endl;
        }
    }
    return 0;
}