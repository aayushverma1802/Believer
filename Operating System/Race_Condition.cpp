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
        /*Race Condition Occurs due to the interal working of 
        "temp"*/
        count = count + 1;
        /*Internally
        
        temp=count+1
        count=temp
        
        This creates a Race condition in our OS
        */
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
