#include <iostream>
// #include <map>
#include <cctype>
using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    // map<char,char>mp;
    for(auto &i:a) i=tolower(i);
    for(auto &i:b) i=tolower(i);
    if(a<b) cout<<"-1";
    else if(a==b) cout<<"0";
    else  cout<<"1";
    return 0;
}