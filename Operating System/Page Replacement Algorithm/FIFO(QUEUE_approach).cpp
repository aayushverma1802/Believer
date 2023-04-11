#include <bits/stdc++.h>
using namespace std;

void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    for (int i = 0; i < 5; i++)
        q.push(i);

    cout << "Elements of queue-";

    print_queue(q);

    int removedele = q.front();
    q.pop();
    cout << "removed element-" << removedele << endl;

    print_queue(q);

    int head = q.front();
    cout << "head of queue-" << head << endl;
    int size = q.size();
    cout << "Size of queue-" << size;

    return 0;
}
