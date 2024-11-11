class Solution
{ 
public:
    int passThePillow(int n, int time)
    {
        int direction = 1; // move in the forward
        int ans = 1;       // Store the ans;
        // ans=1 because atleast one person is there
        while (time > 0)
        {
            ans += direction;
            if (ans == n)
            {
                direction = -1;
            }
            else if (ans == 1)
            {
                direction = 1;
            }
            time--;
        }
        return ans;
    }
};
