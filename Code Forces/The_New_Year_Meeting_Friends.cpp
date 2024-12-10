#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<sstream>
using namespace std;
int main(){
    int f,m,e;
    string t;
    getline(cin,t);
    int tempp;
    stringstream ss(t);
    set<int>s;
    vector<int>v;
    while(ss>>tempp){
        if(tempp>=1 and tempp<=100)
            s.insert(tempp);
    }
    for(auto &i:s){
         v.push_back(i);
    }
    cout<<(v[1]-v[0])+v[2]-v[1];

    return 0;
}