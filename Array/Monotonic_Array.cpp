class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        // Optimized Approach
        int i = 0, j = 0;
        while (i < n and j < m)
        {
            if (nums1[i] <= nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] >= nums2[j])
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < m)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        // Brute Force Approach

        // for(auto i:nums1){
        //     ans.push_back(i);
        // }
        // for(auto i:nums2){
        //     ans.push_back(i);
        // }
        // sort(ans.begin(),ans.end());
        int s = ans.size();
        cout << s;
        double c = 0;
        if (s % 2 == 0)
        {
            c = (double)(ans[(s / 2) - 1] + ans[(s / 2)]);
            cout << c;
            c = (double)c / 2;
            cout << c;
        }
        else
        {

            c = (double)ans[s / 2];
            cout << c;
        }

        return c;
    }
};