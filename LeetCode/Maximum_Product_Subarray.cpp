class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        // size of array
        int n = arr.size();
        int ans = arr[0];
        int ma = ans;
        int mi = ans;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(ma, mi);
            }
            ma = max(arr[i], ma * arr[i]);
            mi = min(arr[i], mi * arr[i]);
            ans = max(ans, ma);
        }
        return ans;
    }
};