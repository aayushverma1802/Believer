class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        // The change which i have;
        int five = 0;
        int ten = 0;

        for (auto i : bills)
        {
            if (i == 5)
            {
                five++;
            }
            else if (i == 10)
            {
                if (five)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (five > 0 and ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }

                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};