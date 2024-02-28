class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, vector<int> &dp)
    {
        if (i == s.length())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int minCost = INT_MAX;
        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                int cost = 1 + solve(s, j + 1, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string s)
    {
        vector<int> dp(s.length() + 1, -1);

        // we subtract 1 because code includes a partition at the end of the string as well
        return solve(s, 0, dp) - 1;
    }
};