#include<iostream>
// #include<bits/stdc++.h>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string n;
    int k,l,c,dp,nl,np;
        getline(cin,n);
        stringstream ss(n);
        int temp;
        vector<int>ans;
        while(ss>>temp){
            if(temp>=1 and temp<=1000)
                ans.push_back(temp);
            
        }
        int milli=(ans[1]*ans[2])/(ans[0]*ans[6]);
        int limes=(ans[3]*ans[4])/ans[0];
        int salt=ans[5]/(ans[7]*ans[0]);
        cout<<(min(milli,min(limes,salt)));


        return 0;
}