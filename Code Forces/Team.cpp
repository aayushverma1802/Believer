#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cnt = 0;

    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1 and b == 1)
        {
            cnt++;
        }
        else if (b == 1 and c == 1)
        {
            cnt++;
        }
        else if(a==1 and c==1){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}