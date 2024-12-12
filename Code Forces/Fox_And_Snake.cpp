#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    bool flag = false;
    string ans[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2 == 0)
            {
                ans[i][j] = "#";
            }
            else
            {
                if (!flag and j == m-1)
                {
                    ans[i][j] = "#";
                }
                else if (flag and j == 0)
                {
                    ans[i][j] = "#";
                }
                else
                {
                    ans[i][j] = ".";
                }
            }
        }
        if (i % 2 != 0)
        {
            // Toggle flag after processing odd row
            flag = !flag;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}