class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &interval)
    {
        int n = interval.size();
        sort(interval.begin(), interval.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() == true)
            {
                ans.push_back(interval[i]);
            }
            else
            {
                int y = ans.back()[1];
                // Overlapping
                if (interval[i][0] <= y)
                {
                    ans.back()[1] = max(y, interval[i][1]);
                }
                // Not Overlapping
                else
                {
                    ans.push_back(interval[i]);
                }
            }
        }
        return ans;
    }
};