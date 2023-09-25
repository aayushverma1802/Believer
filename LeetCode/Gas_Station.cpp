class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int start = 0;
        int Reqfuel = 0;
        int extrafuel = 0;
        for (int i = 0; i < n; i++)
        {
            extrafuel += gas[i] - cost[i];
            if (extrafuel < 0)
            {
                start = i + 1;
                Reqfuel += extrafuel;
                extrafuel = 0;
            }
        }
        if (Reqfuel + extrafuel >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};