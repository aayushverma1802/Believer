class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int result = 0;
        for (int i = 1; i < arrays.size(); i++)
        {
            int curr_ele_maxi = arrays[i].back();
            int curr_ele_mini = arrays[i].front();
            result = max(result, max(abs(curr_ele_mini - maxi), abs(curr_ele_maxi - mini)));
            maxi = max(maxi, curr_ele_maxi);
            mini = min(mini, curr_ele_mini);
        }
        return result;
    }
};