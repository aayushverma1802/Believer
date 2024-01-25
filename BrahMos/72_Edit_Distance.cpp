class Solution
{
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>> &dp)
    {

        if (j == w2.size())
        {
            return w1.size() - i;
        }
        if (i == w1.size())
        {
            return w2.size() - j;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (w1[i] == w2[j])
        {
            return dp[i][j] = solve(w1, w2, i + 1, j + 1, dp);
        }
        int a = 1 + solve(w1, w2, i + 1, j, dp);
        int b = 1 + solve(w1, w2, i, j + 1, dp);
        int c = 1 + solve(w1, w2, i + 1, j + 1, dp);
        return dp[i][j] = min(a, min(b, c));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + m, vector<int>(n + m, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};