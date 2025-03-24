class Solution
{
public:
    // Brute Force
    // bool solve(int n) {
    //     int arr[3] = {2, 3, 5};
    //     for (int i : arr) {
    //         while (n % i == 0) {
    //             n /= i;
    //         }
    //     }
    //     return n == 1;
    // }

    // int nthUglyNumber(int n) {
    //     int cnt = 0;
    //     int i = 1; // Start from 1
    //     while (cnt < n) {  // Stop when we find `n` ugly numbers
    //         if (solve(i)) {
    //             cnt++;
    //         }
    //         i++;  // Move to the next number
    //     }
    //     return i - 1;  // The last ugly number found
    // }

    // Optimized Code
    int nthUglyNumber(int n)
    {
        vector<int> arr(n + 1);
        int i2;
        int i3;
        int i5;
        i2 = i3 = i5 = 1;
        arr[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ug2 = arr[i2] * 2;
            int ug3 = arr[i3] * 3;
            int ug5 = arr[i5] * 5;
            int minug = min({ug2, ug3, ug5});
            arr[i] = minug;
            if (ug2 == minug)
            {
                i2++;
            }
            if (ug3 == minug)
            {
                i3++;
            }
            if (ug5 == minug)
            {
                i5++;
            }
        }
        return arr[n];
    }
};
