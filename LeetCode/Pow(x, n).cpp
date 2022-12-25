class Solution
{
public:
    double myPow(double x, int n)
    {
        long double p = x;
        long double q = n;
        return pow(p, q);
    }
};