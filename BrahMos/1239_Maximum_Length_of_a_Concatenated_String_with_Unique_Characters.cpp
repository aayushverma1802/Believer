class Solution
{
public:
    bool dup(string &a, string &b)
    {
        map<int, int> m;
        for (auto &i : b)
        {
            m[i - 'a']++;
            if (m[i - 'a'] > 1)
                return false;
        }
        for (auto i : a)
        {
            if (m[i - 'a'] > 0)
            {
                return false;
            }
        }
        return true;
    }

    int solve(vector<string> &arr, int n, int i, string temp)
    {
        if (i >= n)
        {
            return temp.size();
        }
        int exclude = solve(arr, n, i + 1, temp);
        int include = 0;
        if (dup(temp, arr[i]))
        {
            include = solve(arr, n, i + 1, temp + arr[i]);
        }
        return max(include, exclude);
    }

    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        return solve(arr, n, 0, "");
    }
};
