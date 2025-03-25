#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, char> m;
    string s;
    cin >> s;
    string ans = "";

    // Define mappings
    m["."] = '0';
    m["-."] = '1';
    m["--"] = '2';

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {  
            if (i + 1 < s.size() && s[i + 1] == '.') { 
                ans += m["-."];
                i++; // Skip the next character since it's already used
            } 
            else if (i + 1 < s.size() && s[i + 1] == '-') {  
                ans += m["--"];
                i++; // Skip the next character
            }
        } 
        else { 
            ans += m["."]; // Process single `.`
        }
    }
    cout << ans;
    return 0;
}
