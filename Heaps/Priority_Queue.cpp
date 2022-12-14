#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cout << "\n**MAX Heap**\n\n";
    priority_queue<int> pq;
    // Default this makes the Max Heap.

    pq.push(4);
    pq.push(5);
    pq.push(3);
    pq.push(2);
    // Because this is the Max Heap
    // So the top element will be " 5 ".

    cout << "Element at top:- " << pq.top() << endl;
    pq.pop();
    cout << "Element at top:- " << pq.top() << endl;
    cout << "Size is:- " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "p_q is Empty\n";
    }
    else
    {
        cout << "p_q is not Empty\n";
    }

    // Making of the Min Heap
    priority_queue<int, vector<int>, greater<int>> min_pq;

    min_pq.push(4);
    min_pq.push(5);
    min_pq.push(3);
    min_pq.push(2);
    // Because this is the Min Heap
    // So the top element will be " 2 ".
    cout << "\n**MIN Heap**\n\n";
    cout << "Element at top:- " << min_pq.top() << endl;
    min_pq.pop();
    cout << "Element at top:- " << min_pq.top() << endl;
    cout << "Size is:- " << min_pq.size() << endl;
    if (min_pq.empty())
    {
        cout << "p_q is Empty\n";
    }
    else
    {
        cout << "p_q is not Empty\n";
    }
}