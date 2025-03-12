#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> egg;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        egg.push_back({a, b});
    }
    string ans = "";
    int sa = 0, sb = 0;
    for (auto i : egg)
    {
        if ((sa + i.first) - sb <= 500)
        {
            sa += i.first;
            ans += "A";
        }
        else
        {
            sb += i.second;
            ans += "G";
        }
    }
    cout << ans;

    return 0;
}