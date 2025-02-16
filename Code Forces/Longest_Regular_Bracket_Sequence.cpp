#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<int> st;
    vector<int> valid(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (st.empty() == false)
        {
            int j = st.top();
            st.pop();
            valid[i] = valid[j] = 1;
        }
    }
    int count = 0, ans = 0, maxi = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (valid[i] == 1)
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 0;
        }
    }
    count=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (valid[i] == 1)
        {
            count++;
            if(count==maxi){
                ans++;
            }
        }
        else
        {
            count = 0;
        }

    }
    if(ans==0){
        ans=1;
    }
    cout<<maxi<<" "<<ans<<endl;
    return 0;
}