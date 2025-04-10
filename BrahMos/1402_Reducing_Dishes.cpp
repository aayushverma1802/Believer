class Solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<int> &satisfaction, int index, int time)
    {
        if (index == satisfaction.size())
        {
            return 0;
        }
        if (dp[index][time] != -1)
        {
            return dp[index][time];
        }
        int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
        int exclude = 0 + solve(satisfaction, index + 1, time);
        return dp[index][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        dp.assign(satisfaction.size() + 1, vector<int>(satisfaction.size(), -1));
        sort(begin(satisfaction), satisfaction.end());
        return solve(satisfaction, 0, 0);
    }
};