class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long totalChalk = 0;
        for (int amount : chalk)
        {
            totalChalk += amount;
        }
        k %= totalChalk; // Reduce k to be within the total chalk amount

        for (int i = 0; i < chalk.size(); ++i)
        {
            k -= chalk[i];
            if (k < 0)
            {
                return i;
            }
        }
        return -1; // This line is never reached, but included for completeness
    }
};
