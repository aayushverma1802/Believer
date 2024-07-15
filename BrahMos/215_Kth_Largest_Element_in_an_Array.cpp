class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto i : nums)
        {
            pq.push(i);
        }
        while (k - 1 != 0)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};