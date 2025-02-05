#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // Disables C++ stream synchronization for faster I/O
    cin.tie(NULL); // Unties cin from cout for independent buffering, improving performance

    printf("A\n"); // Prints "A" using C-style I/O
    cout << "B\n"; // Prints "B" using C++ I/O
    printf("C\n"); // Prints "C" using C-style I/O
    cout << "D\n"; // Prints "D" using C++ I/O

    return 0; // Indicates successful program termination
}
// OUTPUT
// A
// C
// B
// D

// These are used to speed up input/output operations:  

// - `ios_base::sync_with_stdio(false);` → **Disables synchronization** between C++ and C I/O for faster execution.  
// - `cin.tie(NULL);` → **Unties `cin` from `cout`**, so input doesn’t wait for output, improving performance.
