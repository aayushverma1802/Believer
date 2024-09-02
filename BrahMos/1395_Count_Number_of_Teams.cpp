class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int total_teams = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int countleft_min = 0;
            int countright_min = 0;
            int countleft_max = 0;
            int countright_max = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] < rating[i])
                {
                    countleft_min++;
                }
                else if (rating[j] > rating[i])
                {
                    countleft_max++;
                }
            }
            for (int k = i + 1; k < n; k++)
            {
                if (rating[i] < rating[k])
                {
                    countright_max++;
                }
                else if (rating[i] > rating[k])
                {
                    countright_min++;
                }
            }
            total_teams += countleft_max * countright_min + countleft_min * countright_max;
        }
        return total_teams;
    }
};