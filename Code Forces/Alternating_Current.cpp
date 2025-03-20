#include<iostream>
#include<stack>
using namespace std;
int main(){ 
    stack<int>st; 
    string s; 
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(!st.empty() and st.top()==s[i])
            st.pop();

        else
            st.push(s[i]);
    }
    st.empty()?puts("Yes"):puts("No");
    return 0;
}
