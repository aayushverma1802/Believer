class Solution
{
public:
    // int getNext(vector<vector<int>>& array, int l, int currentJobEnd, int n) {
    //     return lower_bound(array.begin() + l, array.end(), vector<int>{currentJobEnd, 0, 0}) - array.begin();
    // }

    int getNext(vector<vector<int>> &array, int l, int currentJobEnd, int n)
    {
        int r = n - 1;
        int result = n + 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd)
            { // we can take this task
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>> &array, int i, int n, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int next = getNext(array, i + 1, array[i][1], n);
        int taken = array[i][2] + solve(array, next, n, dp);
        int not_taken = solve(array, i + 1, n, dp);
        return dp[i] = max(taken, not_taken);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<int> dp(n + 1, -1);
        vector<vector<int>> array(n, vector<int>(3, 0)); //{s,e,p}
        for (int i = 0; i < n; i++)
        {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        // sort acc to the starting time
        auto comp = [&](auto &vec1, auto &vec2)
        {
            return vec1[0] < vec2[0];
        };
        sort(begin(array), end(array), comp);
        return solve(array, 0, n, dp);
    }
};