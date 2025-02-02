#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Ignore newline after reading n
    stack<string> st;

    while (n--)
    {
        string s;
        getline(cin, s); // Read full command including spaces

        if (s == "pwd")
        {
            vector<string> temp;
            stack<string> temp_stack = st;

            while (!temp_stack.empty())
            {
                temp.push_back(temp_stack.top());
                temp_stack.pop();
            }

            reverse(temp.begin(), temp.end());
            cout << "/";
            for (auto &i : temp)
            {
                cout << i << "/";
            }
            cout << endl;
        }
        else if (s.substr(0, 3) == "cd ")
        {
            string path = s.substr(3);
            stringstream ss(path);
            string token;

            if (!path.empty() && path[0] == '/')
            {
                // Absolute path: Clear stack
                while (!st.empty())
                {
                    st.pop();
                }
            }

            while (getline(ss, token, '/'))
            {
                if (token == "..")
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else if (!token.empty() && token != ".")
                {
                    st.push(token);
                }   
            }
        }
    }
    return 0;
}
