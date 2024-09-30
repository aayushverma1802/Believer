class Solution
{
public:
    void solve(int curr, int end, vector<int> &result)
    {
        if (end < curr)
        {
            return;
        }
        result.push_back(curr);
        for (int i = 0; i <= 9; i++)
        {
            int new_num = i + curr * 10;
            if (new_num > end)
            {
                return;
            }
            solve(new_num, end, result);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        for (int start = 1; start <= 9; start++)
        {
            solve(start, n, result);
        }
        return result;
    }
};