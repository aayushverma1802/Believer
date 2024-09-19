class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> mintues(n);
        for (int i = 0; i < n; i++)
        {
            string time = timePoints[i];
            string h = time.substr(0, 2);
            string m = time.substr(3);
            int hr = stoi(h);
            int mn = stoi(m);
            mintues[i] = hr * 60 + mn;
        }
        sort(mintues.begin(), mintues.end());
        int ans = INT_MAX;
        for (int i = 1; i < mintues.size(); i++)
        {
            ans = min(ans, mintues[i] - mintues[i - 1]);
        }
        return min(ans, 24 * 60 - mintues[n - 1] + mintues[0]);
    }
};