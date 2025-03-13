#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    while (n--)
    {
        string ans = "";
        string str;
        // getline(cin,str);
        cin >> str;
        if (str.length() > 10)
        {
            ans += str[0];
            int k = str.length() - 2;
            string temp = to_string(k);
            ans += temp;
            ans += str[str.length() - 1];
            cout << ans << endl;
        }
        else
        {
            cout << str << endl;
        }
    }
    return 0;
}