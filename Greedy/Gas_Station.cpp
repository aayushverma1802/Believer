class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int diff = 0;
        int fuel = 0;
        int ttlDist = 0;
        int index = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            diff = gas[i] - cost[i];
            fuel += diff;
            ttlDist += diff;
            if (fuel < 0)
            {
                index = i + 1;
                fuel = 0;
            }
        }
        if (ttlDist < 0)
        {
            return -1;
        }
        return index;
    }
};