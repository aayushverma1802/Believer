class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> ans;
        vector<tuple<int, int, int>> sort_task;
        int index = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        for (int i = 0; i < tasks.size(); i++)
        {
            sort_task.push_back({tasks[i][0], tasks[i][1], i});
        }
        long long int cpu_time = 0;
        int i = 0;
        sort(sort_task.begin(), sort_task.end());
        while (i < n or pq.empty() == false)
        {
            while (i < n and get<0>(sort_task[i]) <= cpu_time)
            {
                pq.push({get<1>(sort_task[i]),
                         {get<2>(sort_task[i]), get<0>(sort_task[i])}});
                i++;
            }
            if (pq.empty() == false)
            {
                auto ttsk = pq.top();
                pq.pop();
                ans.push_back(ttsk.second.first); // push index
                cpu_time += ttsk.first;
            }
            else
            {
                cpu_time = get<0>(sort_task[i]);
            }
        }
        return ans;
    }
};