class Solution
{
public:
    int n;
    bool predecessor(string &prev, string &curr)
    {
        int M = prev.length();
        int N = curr.length();

        if (M >= N || N - M != 1)
            return false;

        int i = 0, j = 0;
        while (i < M && j < N)
        {
            if (prev[i] == curr[j])
            {
                i++;
            }
            j++;
        }
        return i == M;
    }

    int lis(vector<string> &words, int prev_idx, int curr_idx, vector<vector<int>> &dp)
    {
        if (curr_idx == n)
            return 0;

        if (dp[prev_idx + 1][curr_idx] != -1)
        {
            return dp[prev_idx + 1][curr_idx];
        }
        int taken = 0;
        if (prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx]))
            taken = 1 + lis(words, curr_idx, curr_idx + 1, dp);

        int not_taken = lis(words, prev_idx, curr_idx + 1, dp);

        return dp[prev_idx + 1][curr_idx] = max(taken, not_taken);
    }

    static bool myFunction(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {
        // memset(t, -1, sizeof(t));
        n = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        sort(begin(words), end(words), myFunction); // You can select pairs in any order.
        return lis(words, -1, 0, dp);
    }
};
