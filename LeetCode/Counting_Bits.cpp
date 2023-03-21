class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n % 2 == 0)
        {
            return solve(n / 2);
        }
        else
        {
            return solve(n / 2) + 1;
        }
    }
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = solve(i);
        }
        return ans;
    }
};