#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;
    unordered_set<int>st;

    for(auto &i:s){
        st.insert(i);
    }
    st.size()%2==0?cout<<"CHAT WITH HER!":cout<<"IGNORE HIM!";

    return 0;
}