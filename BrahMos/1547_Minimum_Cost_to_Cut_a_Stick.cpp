class Solution
{
public:
    int solve(vector<int> &cuts, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++)
        {
            int ans = cuts[j + 1] - cuts[i - 1] + solve(cuts, i, ind - 1) + solve(cuts, ind + 1, j);
            mini = min(mini, ans);
        }
        return mini;
    }
    int minCost(int n, vector<int> &cuts)
    {

        int i = 0;
        int l = cuts.size();
        vector<vector<int>> dp(l + 1, vector<int>(l + 1, -1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        // cuts.push_back(n);
        // cuts.insert(cuts.begin(),0);

        // int l=cuts.size();
        // sort(cuts.begin(),cuts.end());
        return solve(cuts, 1, l);
        //   return   solve(cuts,1,j);
    }
};