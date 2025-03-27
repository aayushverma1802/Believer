#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> death;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            int health;
            cin >> health;
            pq.push(make_pair(health, -i));
        }
        while (pq.empty() == false)
        {
            auto [health, index] = pq.top();
            pq.pop();
            index = -index;
            death.push_back(index + 1);
            health -= k;
            if (health > 0)
                pq.push({health, -index}); 
        }

        for (int idx : death)
        {
            cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}