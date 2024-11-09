class Solution
{
public:
    typedef long long ll;
    long long minEnd(int n, int x)
    {
        ll num = x;
        for (int i = 1; i < n; i++)
        {

            num = (num + 1) | x;
        }

        return num;
    }
};