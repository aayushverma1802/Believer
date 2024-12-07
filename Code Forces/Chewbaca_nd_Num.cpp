#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int j = n; // Store the original number for comparison
    vector<long long int> numb;

    // If the number is less than 10, output the number itself
    if (n < 10)
    {
        cout << n;
        return 0;
    }

    // Breaking the number into digits
    while (n != 0)
    {
        long long int temp = n % 10;
        numb.push_back(temp);
        n /= 10;
    }

    // Reverse to get the original order of digits
    reverse(numb.begin(), numb.end());

    bool flag = false; // To track if any digit was changed

    // Modify the digits based on the condition
    for (long long int i = 0; i < numb.size(); i++)
    {
        long long int temp = numb[i];

        // If changing the digit results in a smaller number, do it
        if ((9 - temp < temp) && !(i == 0 && 9 - temp == 0))
        {
            numb[i] = 9 - temp; // Modify the digit
            flag = true;         // Set flag to true if any digit was modified
        }
    }

    // Reconstruct the number using the digits in the vector
    long long int ans = 0;
    for (long long int i = 0; i < numb.size(); i++)
    {
        ans = ans * 10 + numb[i]; // Rebuild the number
    }

    // If any digit was modified, print the modified number; otherwise, print the original number
    flag ? cout << ans : cout << j;

    return 0;
}
