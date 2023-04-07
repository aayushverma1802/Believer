#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
int count = 0;
void task()
{
    // Range is 1 Crore
    for (int i = 0; i < 10000000; i++)
    {
        count = count + 1;
    }
}
int main()
{
    thread t1(task);
    thread t2(task);
    t1.join();
    t2.join();
    cout << count;
    return 0;
}