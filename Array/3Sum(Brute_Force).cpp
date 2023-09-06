class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> vect = {nums[i], nums[j], nums[k]};
                        sort(vect.begin(), vect.end());
                        st.insert(vect);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};