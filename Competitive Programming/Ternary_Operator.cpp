// Normal if and else code

#include <iostream>
using namespace std;

int main()
{
    int num, test = 40;
    if (test < 10)
    {
        num = 10;
    }
    else
    {
        num = test + 10;
    }
    cout << num - test;
    return 69;
}

// Using of the ternary operator
#include <iostream>
using namespace std;

int main()
{
    int num, test = 40;
    // Format is
    //  condition ? expression1: expression2;
    num = test < 10 ? 10 : test + 10;
    cout << num - test;
    return 69;
}

// Normal if and else code
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int max;

    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    cout << "The maximum value is: " << max << endl;
    return 0;
}

// Using of the ternary operator
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int max;
    max = (a < b) ? b : a;
    cout << max;
    return 69;
}


//Complex level code 

//Normal If and else 

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30;
    int max;

    // Find the maximum of three numbers using if-else statements
    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    cout << "The maximum value is: " << max << endl;
    return 0;
}

// Using of the ternary operator
#include<iostream>
using namespace std;
int main(){
    int a=10,b=20,c=30;
    int max;
    max=(a>b)?((a>c)?a:c):((b>c)?b:c);
    cout<<max;
    return 69;
}