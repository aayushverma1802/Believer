#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    //Lower_bound case
    vector<int> arr = {10, 20, 30, 40};
    auto it = lower_bound(arr.begin(), arr.end(), 25);
    cout << (it - arr.begin())<<endl; // Output: 2 (index of 30)

    // upper_bound case
    vector<int> a = {10, 20, 30, 30, 40, 50};
    it = upper_bound(a.begin(), a.end(), 30);
    cout << (it - a.begin()); // Output: 4 (First index after all 30s)
}
// Element	Value	Address (Example)
// 0	      10	1000
// 1	      20	1004
// 2          30	1008
// 3	      40	1012
// 4	      50	1016
// auto it = lower_bound(arr.begin(), arr.end(), 30);
// it - arr.begin();  // Gives index


// it (points to 30, at 1008)
//  arr.begin() (points to 10, at 1000)


// Logic
//  (1008 - 1000) / (size of int)   // C++ does this automatically
//  = 8 / 4
//  = 2  (Index of 30)
