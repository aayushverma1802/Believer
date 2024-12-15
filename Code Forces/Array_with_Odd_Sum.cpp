#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    vector<long long int> cal;
    for (long long int i = 0; i < n; i++)
    {
        long long int m;
        cin >> m;
        cal.clear();
        int odd=0;
        int even=0;
        for (long long int j = 0; j < m; j++)
        {
            long long int k;
            cin >> k;
            cal.push_back(k);
        }
        int sum=0;
        for(auto ik:cal){
            sum+=ik;
            if(ik%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(sum%2!=0 or (even  and odd)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
        
    }
    return 0;
}