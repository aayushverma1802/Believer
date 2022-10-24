#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

 
int 
main () 
{
  
 
map < int, string > m;
  
 
pair < int, string > p;
  
 
int n;
  
 
string a;
  
 
cout << "Enter the size of the Hashmap\n";
  
 
cin >> n;
  
 
for (int i = 0; i < n; i++)
    
    {
      
 
cout << "Enter the String\n";
      
 
cin >> a;
      
 
m[i] = a;
  
 
} 
for (int j = 0; j < n; j++)
    
    {
      
 
cout << j << " ";
      
cout << m[j] << endl;

 
 
} 
} 
