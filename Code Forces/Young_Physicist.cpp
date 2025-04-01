#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int sum_x = 0, sum_y = 0, sum_z = 0;

    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }

    (sum_x == 0 && sum_y == 0 && sum_z == 0) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
