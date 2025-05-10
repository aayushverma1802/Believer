class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<tuple<int, int, int>>
            pq;

        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (pq.size() < k) {
                    pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                } else if (nums1[i] + nums2[j] < get<0>(pq.top())) {
                    pq.pop();
                    pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                } else {
                    break;
                }
            }
        }
        while (pq.empty() == false) {
            auto [x, y, z] = pq.top();
            pq.pop();
            ans.push_back({y, z});
        }

        return ans;
    }
};