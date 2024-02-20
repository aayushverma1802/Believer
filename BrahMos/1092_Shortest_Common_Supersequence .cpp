class Solution
{
public:
    // Function to find the length of the longest common subsequence
    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base case: If either of the strings is empty, the LCS is 0.
        if (ind1 == 0 || ind2 == 0)
        {
            return 0;
        }
        // If the subproblem has already been solved, return the stored result.
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        // If the characters at the current indices are the same, include them in the LCS.
        if (s1[ind1 - 1] == s2[ind2 - 1])
        {
            // Move to the previous indices for both strings and find the LCS.
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
        }
        else
        {
            // If the characters are different, try all possibilities by excluding one character at a time
            // and find the maximum LCS length.
            return dp[ind1][ind2] = max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
        }
    }

    // Function to find the shortest common supersequence of two strings
    string shortestCommonSupersequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        // Create a DP table to store the LCS lengths for different substrings of s1 and s2.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Find the length of the longest common subsequence between s1 and s2.
        int lcsLength = f(n, m, s1, s2, dp);

        int i = n;
        int j = m;
        string ans = "";

        // Reconstruct the shortest common supersequence by backtracking the DP table.
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters are the same, include only one occurrence in the supersequence.
                ans += s1[i - 1];
                i--;
                j--;
                lcsLength--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // If the characters are different, choose the character which contributed to the LCS.
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }

        // Add the remaining characters from s1 and s2, if any, to the supersequence.
        while (i > 0)
        {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += s2[j - 1];
            j--;
        }

        // Reverse the supersequence to get the correct order of characters.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};