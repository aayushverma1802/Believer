//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n)
    {
        if ((newx >= 0 and newx < n) and (newy >= 0 and newy < n) and
            vis[newx][newy] != 1 and arr[newx][newy] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
               vector<vector<bool>> &vis, string path)
    {
        // base case
        if (x == n - 1 and y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // 4 movement

        // D,L,R,U

        // Down
        if (isSafe(x + 1, y, vis, arr, n))
        {
            vis[x][y] = 1;
            solve(x + 1, y, arr, n, ans, vis, path + 'D');
            vis[x][y] = 0;
        }
        // Left
        if (isSafe(x, y - 1, vis, arr, n))
        {
            vis[x][y] = 1;
            solve(x, y - 1, arr, n, ans, vis, path + 'L');
            vis[x][y] = 0;
        }
        // Right
        if (isSafe(x, y + 1, vis, arr, n))
        {
            vis[x][y] = 1;
            solve(x, y + 1, arr, n, ans, vis, path + 'R');
            vis[x][y] = 0;
        }
        // Up
        if (isSafe(x - 1, y, vis, arr, n))
        {
            vis[x][y] = 1;
            solve(x - 1, y, arr, n, ans, vis, path + 'U');
            vis[x][y] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        string path = "";
        if (m[0][0] == 0)
        {
            return ans;
        }
        solve(0, 0, m, n, ans, vis, path);
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
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends