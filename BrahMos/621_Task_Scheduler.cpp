class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        vector<int> m(26, 0);
        for (char &i : tasks)
        {
            m[i - 'A']++;
        }
        sort(m.begin(), m.end());
        int maxFre = m[25];
        int hole = maxFre - 1;
        int idleSlots = n * hole;
        for (int i = 24; i >= 0; i--)
        {
            idleSlots -= min(m[i], hole);
        }
        return idleSlots > 0 ? tasks.size() + idleSlots : tasks.size();
    }
};