#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int ans = 0;

        // Read Red Sequence
        int n;
        cin >> n;
        vector<int> red(n);
        for (int i = 0; i < n; i++) {
            cin >> red[i];
        }

        // Calculate max prefix sum for red
        int maxr = 0, sumr = 0;
        for (int i = 0; i < n; i++) {
            sumr += red[i];
            maxr = max(maxr, sumr);
        }

        // Read Blue Sequence
        int m;
        cin >> m;
        vector<int> blue(m);
        for (int i = 0; i < m; i++) {
            cin >> blue[i];
        }

        // Calculate max prefix sum for blue
        int maxb = 0, sumb = 0;
        for (int i = 0; i < m; i++) {
            sumb += blue[i];
            maxb = max(maxb, sumb);
        }

        // Correct output
        cout << maxr + maxb << endl;
    }

    return 0;
}
