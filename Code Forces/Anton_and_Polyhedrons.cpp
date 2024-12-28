#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{ 
    unordered_map<string, int> m;
    m.insert({"Icosahedron", 20});
    m.insert({"Cube", 6});
    m.insert({"Tetrahedron", 4});
    m.insert({"Dodecahedron", 12});
    m.insert({"Octahedron", 8});
    int n;
    cin >> n;
    int ans = 0;

    while (n != 0)
    {
        string gett;
        cin >> gett;
        if (m.find(gett) != m.end())
        {
            ans += m[gett];
        }
        n--;
    }
    cout << ans << endl;

    return 0;
}
