` //{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
    using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                // cout<<arr[i][j]<<"  l";
                pq.push(arr[i][j]);
            }
        }
        // sort(ans.begin(),ans.end());
        while (pq.empty() == false)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends