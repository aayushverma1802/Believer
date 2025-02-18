#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    while (n--)
    {
        int m;
        cin >> m;
        vector<int> ans(m, 0);
        vector<int> cake(m, 0);
        int temp = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> cake[i];
        }
        for (int i = m - 1; i >= 0; i--)
        {
            if (temp != 0 or cake[i]!=0)
            {
                ans[i] = 1;
                temp = max(cake[i], temp);
                temp--;
            }
            else
            {
                temp = cake[i];
            }
        }
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}