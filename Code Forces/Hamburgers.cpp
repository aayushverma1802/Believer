#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long calculateCost(long long x, long long needB, long long needS, long long needC, long long b, long long s, long long c, long long pB, long long pS, long long pC) {
    long long costB = max(0LL, needB * x - b) * pB;
    long long costS = max(0LL, needS * x - s) * pS;
    long long costC = max(0LL, needC * x - c) * pC;
    return costB + costS + costC;
}

int main() {
    string recipe;
    long long b, s, c, pB, pS, pC, r;
    cin >> recipe >> b >> s >> c >> pB >> pS >> pC >> r;

    long long needB = count(recipe.begin(), recipe.end(), 'B');
    long long needS = count(recipe.begin(), recipe.end(), 'S');
    long long needC = count(recipe.begin(), recipe.end(), 'C');

    long long low = 0, high = 1e13, ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (calculateCost(mid, needB, needS, needC, b, s, c, pB, pS, pC) <= r) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
