class Solution
{
public:
    int solve(int n, vector<int> &days, vector<int> &cost, int index)
    {
        // Base Case
        if (index >= n)
        {
            return 0;
        }
        // 1 day pass
        int op1 = cost[0] + solve(n, days, cost, index + 1);
        // 7 day pass
        int i;
        for (i = index; i < n and days[i] < days[index] + 7; i++)
            ;
        int op2 = cost[1] + solve(n, days, cost, i);

        // 30 day pass
        for (i = index; i < n and days[i] < days[index] + 30; i++)
            ;
        int op3 = cost[2] + solve(n, days, cost, i);

        return min(op1, min(op2, op3));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        return solve(n, days, costs, 0);
    }
};