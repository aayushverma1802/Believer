class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            // Width keeps changing
            int w = j - i;
            // Minimum height can only store the water
            int h = min(height[i], height[j]);
            ans = max(ans, h * w);
            if (height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};