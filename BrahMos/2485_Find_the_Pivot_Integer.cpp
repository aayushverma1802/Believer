class Solution
{
public:
    int pivotInteger(int n)
    {

        int i = 0;
        int ans = -1;
        if (n == 1)
        {
            return 1;
        }
        while (i < n)
        {
            int k = 0;
            int j = i;
            int left_ans = 0;
            int right_ans = 0;
            while (k <= j)
            {
                left_ans += k;
                k++;
            }
            while (j <= n)
            {
                right_ans += j;
                j++;
            }
            cout << left_ans << " " << right_ans << endl;

            if (right_ans == left_ans)
            {
                ans = i;
            }
            i++;
        }

        return ans;
    }
};