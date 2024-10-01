class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> remainderCount(k, 0);
        for (auto &i : arr)
        {
            int rem = (i % k + k) % k;
            remainderCount[rem]++;
        }
        if (remainderCount[0] % 2 != 0)
        {
            return false;
        }
        for (auto i = 1; i <= k / 2; i++)
        {
            int counterHalf = k - i;
            if (remainderCount[counterHalf] != remainderCount[i])
            {
                return false;
            }
        }
        return true;
    }
};