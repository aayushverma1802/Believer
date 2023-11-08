int n = nums.size();
priority_queue<int, vector<int>, greater<int>> pq;
for (int i = 0; i < n; i++)
{
    int sum = 0;
    for (int j = i; j < n; j++)
    {
        sum += nums[j];
        if (pq.size() < k)
        {
            pq.push(sum);
        }
        else
        {
            if (pq.top() < sum)
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }
}
return pq.top();
}