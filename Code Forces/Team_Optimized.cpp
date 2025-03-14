#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) {  // Directly checking the sum
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
