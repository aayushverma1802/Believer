#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;
int count = 0;
mutex m;
void task()
{
    // Range is 1 Crore
    m.lock();
    for (int i = 0; i < 10000000; i++)
    {
        count = count + 1;
        
    }
    m.unlock();
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