#include<iostream>
#include<sstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    stringstream ss(s);
    string token;
    vector<int>ans;

    while(getline(ss,token,'+')){
        int temp=token[0]-'0';
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    string take="";
    for(auto &i:ans){
        take+=to_string(i)+'+';

    }
    take.pop_back();
    cout<<take;

    return 0;
}