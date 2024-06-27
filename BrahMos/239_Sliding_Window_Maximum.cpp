// When new element comes nums[i], make space for it (window size can't be greater than k)
// 2. Now, when nums [i] comes, there is no need to keep small elements in that window, pop them

// 3. Now push i in deque -> for nums [i]
// 4. If (1 >= k-1), then deq.front() is our answer for that window

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (dq.empty() == false and dq.front() < i - k + 1)
            {
                dq.pop_front();
            }
            while (dq.empty() == false and nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};