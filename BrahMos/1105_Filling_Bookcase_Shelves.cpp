class Solution
{
public:
    int n;
    int WIDTH;

    int solve(vector<vector<int>> &books, int i, int remainW, int maxHt, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return maxHt;
        }

        if (dp[i][remainW] != -1)
        {
            return dp[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        // Keep the book on the current shelf
        if (bookW <= remainW)
        {
            keep = solve(books, i + 1, remainW - bookW, max(maxHt, bookH), dp);
        }

        // Skip and start a new shelf
        skip = maxHt + solve(books, i + 1, WIDTH - bookW, bookH, dp);

        return dp[i][remainW] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        n = books.size();
        WIDTH = shelfWidth;

        // Initialize the dp vector with -1
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));

        return solve(books, 0, shelfWidth, 0, dp);
    }
};
