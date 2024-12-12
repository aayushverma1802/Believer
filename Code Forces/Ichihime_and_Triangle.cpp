#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> a >> b >> c >> d;

        if (a < 1 || b < a || c < b || d < c || d > 1000000000)
        {
            return 0;
        }
        cout<<b<<" "<<c<<" "<<c;
        cout<<endl;
    }
    
    return 0;
}