#include <iostream>
using namespace std;

int main()
{
    // Enter the string
    // This normal cin method will not be able to take space and whitespaces
    string a;
    cin >> a;          // Reads a single word
    cout << a << endl; // Outputs the word

    // Clear the input buffer before using getline
    cin.ignore(); // Ignores the leftover '\n' character

    // Using getline to take full sentences until Enter is pressed
    string b;
    getline(cin, b);   // Reads the entire line
    cout << b << endl; // Outputs the full line

    return 69; // Just an unconventional return value
}
