class Solution
{
public:
    int dp[501][501][2];
    int find(int i, int j, vector<int> &nums1, vector<int> &nums2, bool taken)
    {
        if (i >= nums1.size() || j >= nums2.size())
        {
            return (taken) ? 0 : INT_MIN;
        }
        if (dp[i][j][taken] != -1) // if calculated previously then return directly
            return dp[i][j][taken];
        int ans = INT_MIN;

        int curr = nums1[i] * nums2[j];
        ans = max(ans, curr + find(i + 1, j + 1, nums1, nums2, 1)); // take both
        ans = max(ans, find(i, j + 1, nums1, nums2, taken));        // fix i and move j
        ans = max(ans, find(i + 1, j, nums1, nums2, taken));        // fix j and move i

        return dp[i][j][taken] = ans;
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        memset(dp, -1, sizeof(dp));
        int ans = find(0, 0, nums1, nums2, 0);
        return ans;
    }
};