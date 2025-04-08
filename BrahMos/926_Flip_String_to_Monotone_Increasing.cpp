class Solution
{
public:
    vector<vector<int>> dp;
    int n;
    int solve(string &s, int curr_index, int prev)
    {
        if (curr_index >= n)
        {
            return 0;
        }
        int flip = INT_MAX;
        int not_flip = INT_MAX;
        if (dp[curr_index][prev] != -1)
        {
            return dp[curr_index][prev];
        }
        if (s[curr_index] == '0')
        {
            if (prev == 1)
            {
                flip = 1 + solve(s, curr_index + 1, 1);
            }
            else
            {
                flip = 1 + solve(s, curr_index + 1, 1);
                not_flip = solve(s, curr_index + 1, 0);
            }
        }
        if (s[curr_index] == '1')
        {
            if (prev == 1)
            {
                flip = solve(s, curr_index + 1, 1);
            }
            else
            {
                flip = 1 + solve(s, curr_index + 1, 0);
                not_flip = solve(s, curr_index + 1, 1);
            }
        }
        return dp[curr_index][prev] = min(flip, not_flip);
    }
    int minFlipsMonoIncr(string s)
    {
        n = s.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0);
    }
};