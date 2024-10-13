class Solution
{
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        //{depart,char} pair<int,int>
        //{freechair}
        priority_queue<P, vector<P>, greater<P>> occupied;   //{departTime,charno}
        priority_queue<int, vector<int>, greater<int>> free; // min indexed available chair
        int targetFriendArrivalTime = times[targetFriend][0];
        int chairNo = 0;
        sort(begin(times), end(times)); // based on arrival time
        for (int i = 0; i < n; i++)
        {
            int arrival = times[i][0];
            int depart = times[i][1];
            while (!occupied.empty() and occupied.top().first <= arrival)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }
            if (free.empty())
            {
                // no free chairs available
                occupied.push({depart, chairNo});
                if (arrival == targetFriendArrivalTime)
                {
                    return chairNo;
                }
                chairNo++;
            }
            else
            {
                int leastChairAvailable = free.top();
                free.pop();
                if (arrival == targetFriendArrivalTime)
                {
                    return leastChairAvailable;
                }
                occupied.push({depart, leastChairAvailable});
            }
        }
        return -1;
    }
};