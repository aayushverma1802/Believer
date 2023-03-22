class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> ans(4, 0);
        int i = 0;
        while (num)
        {
            ans[i++] = num % 10;
            num /= 10;
        }

        sort(ans.begin(), ans.end());
        // new1 is small due to sort so make them
        // more significant.
        int new1 = ans[0] * 10 + ans[1] * 10;
        // new2 is big due to sort so make them
        // less significant
        int new2 = ans[2] + ans[3];
        return new1 + new2;
    }
};