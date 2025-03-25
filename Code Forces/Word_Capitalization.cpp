#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    if(s[0]>='a' and s[0]<='z')
        s[0]=s[0]-'a'+'A';
    cout<<s;

}   