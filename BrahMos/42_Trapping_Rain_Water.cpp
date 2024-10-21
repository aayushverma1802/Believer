class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = heights[0];
        right[n - 1] = heights[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(heights[i], left[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(heights[i], right[i + 1]);
        }
        // Now all the preprocessing is done
        // Time to evaluate the max height the water can store while its raining
        int storedWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            storedWater += min(left[i], right[i]) - heights[i];
        }
        return storedWater;
    }
};