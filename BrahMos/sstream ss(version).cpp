#include <bits/stdc++.h>
using namespace std;
int main()
{
    string version = "1.2.3";
    stringstream ss(version);
    string token;
    vector<string> store; // Vector to store the tokens
    while (getline(ss, token, '.'))
    {
        store.push_back(token); // Store each token in the vector
    }
    // Print the tokens to verify
    for (auto &str : store)
    {
        cout << str << " ";
    }

    return 69;
}
