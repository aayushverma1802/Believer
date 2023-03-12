//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    // your code here
    bool flag = false;
    int m = str.size();
    int n = pat.size();
    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (str[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == n)
        {
            // cout<<"Pattern Found at index\n"<<i<<endl;
            flag = true;
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str, pat;
        cin >> str;
        cin >> pat;

        if (searchPattern(str, pat) == true)
            cout << "Present" << endl;
        else
            cout << "Not present" << endl;
    }
}

// } Driver Code Ends