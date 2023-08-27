class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        stack<int> st;
        int n = nums2.size();
        int res;
        for (int i = n - 1; i >= 0; i--)
        {
            int ele = nums2[i];
            while (!st.empty() and st.top() <= ele)
            {
                st.pop();
            }
            if (st.empty())
            {
                res = -1;
            }
            else
            {
                res = st.top();
            }

            umap.insert({ele, res});
            st.push(ele);
        }
        vector<int> ans;
        for (auto x : nums1)
        {
            ans.push_back(umap[x]);
        }
        return ans;
    }
};