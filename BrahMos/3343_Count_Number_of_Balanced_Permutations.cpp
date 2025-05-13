class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        sort(num.begin(), num.end());
        int cnt = 0;
        unordered_set<string> seen;

        do
        {

            if (seen.count(num))
            {
                continue;
            }
            seen.insert(num);
            //  int n = num.size();
            int odd = 0;
            int even = 0;
            for (int i = 0; i < num.size(); i++)
            {
                int digit = num[i] - '0';
                if (i & 1)
                {
                    odd += digit;
                }
                else
                {

                    even += digit;
                }
            }

            if (odd == even)
            {
                cnt++;
            }
        } while (next_permutation(num.begin(), num.end()));
        return cnt;
    }
};