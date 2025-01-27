#include <iostream>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
int main()
{
    // Magic powdwer
    int n, k;
    cin >> n >> k;
    // This is the min requirments
    vector<int> req(n);
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    // This is the amount that we have
    vector<int> have(n);
    for (int i = 0; i < n; i++)
    {
        cin >> have[i];
    }
    int low = 0, high = 2001;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cost = 0;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            cost += max(z, req[i] * mid - have[i]);
        }
        if (cost <= k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high << endl;
    return 0;
}