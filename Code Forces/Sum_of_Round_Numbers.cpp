#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ans.clear();
        int num;
        cin >> num;
        int pow = 1;
        while (num)
        {
            int a = num % 10;
            if (a > 0)
            {
                ans.push_back(a * pow);
            }
            pow *= 10;
            num /= 10;
        }
        cout << ans.size() << endl;
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}