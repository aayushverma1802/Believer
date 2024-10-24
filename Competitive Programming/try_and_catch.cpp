#include <iostream>
using namespace std;
int main()
{
    int num1 = 10;
    int num2 = 0;
    try
    {
        if (num2 == 0)
        {
            throw "Cannot Divide with Zero";
        }
        cout << num1 / num2 << endl;
    }
    catch (const char *msg)
    {
        cout << "Error" << msg << endl;
    }
    return 0;
}
