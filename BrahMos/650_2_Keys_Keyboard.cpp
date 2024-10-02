class Solution
{
public:
    int solve(int copy, int curr, int n)
    {
        if (copy == n)
        {
            return 0;
        }
        if (copy > n)
        {
            return INT_MAX / 2;
        }
        int cpy = 1 + 1 + solve(copy + copy, copy, n);
        int paste = 1 + solve(copy + curr, curr, n);
        return min(paste, cpy);
    }
    int minSteps(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        return 1 + solve(1, 1, n);
    }
};