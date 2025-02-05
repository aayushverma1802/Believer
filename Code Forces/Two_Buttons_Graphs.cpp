#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXNode = 1e5 + 7;
int bfs(int n, int m)
{
    vector<int> Dist(MAXNode, -1);
    Dist[n] = 0;
    queue<int> q({n});
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        // The two process as discussed
        int x = u * 2;
        int y = u - 1;
        for (auto i : {x, y})
        {

            if (i >= 0 && i < MAXNode && Dist[i] == -1)
            {
                Dist[i] = 1 + Dist[u];
                q.push(i);
            }
        }
    }
    return Dist[m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m);
    return 0;
}