class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        long long int ans = 0;
        int val = skill[i] + skill[j];
        while (i < j)
        {
            int total = skill[i] * skill[j];
            if (skill[i] + skill[j] != val)
            {
                return -1;
            }
            else
            {
                ans += total;
            }
            i++;
            j--;
        }
        return ans;
    }
};