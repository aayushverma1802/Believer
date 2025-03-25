#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int cnt=0;
    while(a<=b){
        cnt++;
        // cout<<a<<" "<<b<<endl;
        a*=3;
        b*=2;
    }
    cout<<cnt;
    return 0;
}