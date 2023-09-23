class Solution
{
public:
    int reverse(int x)
    {
        long long int i = 0;
        stack<long long int> s;
        long long int lc = pow(-2, 31);
        long long int hc = pow(2, 31) - 1;
        cout << lc << " ";
        cout << hc << " ";

        while (x > 0)
        {
            long long int a = x % 10;
            x /= 10;
            cout << a << " ";
            s.push(a);
        }
        while (x < 0)
        {
            long long int a = x % 10;
            x /= 10;
            cout << a << " ";
            s.push(a);
        }
        long long int ans = 0;
        while (s.empty() == false)
        {
            long long int aj = s.top();

            s.pop();
            ans += aj * pow(10, i);
            i++;
        }
        if (ans >= hc or ans <= lc)
        {
            return 0;
        }
        return ans;
    }
};