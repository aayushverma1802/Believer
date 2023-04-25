#include<bits/stdc++.h>
using namespace std;
int main(){
	double a=100000;
	double b=100000;
	double c=a*b;
	cout<<"Output before Fixed keyword"<<endl;
	cout<<c<<endl;
	cout<<"Output after Fixed keyword"<<endl;
	cout<<fixed<<c<<endl;
	
//	setprecision(0):-Don't print 0 after the decimal.
cout<<cout<<fixed<<setprecision(0)<<c<<endl;
//	cout<<"Done";
	return 69;
}
