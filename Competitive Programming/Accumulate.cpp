#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (auto i : v)
    {
        sum += i;
    }
    cout << "Sum of all the element in the dynamic array is:- " << sum << endl;
    cout << "Sum of all the element in the dynamic array in accumulate is:- " << accumulate(begin(v), end(v), 0) << endl;

    return 69;
}