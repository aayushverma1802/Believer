class Solution
{
public:
    bool isValid(string x)
    {
        stack<char> s;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '(' or x[i] == '[' or x[i] == '{')
            {
                s.push(x[i]);
            }
            else if (x[i] == ')' or x[i] == ']' or x[i] == '}')
            {
                if (s.empty())
                {
                    return false;
                }

                else if ((s.top() == '(' && x[i] == ')') || (s.top() == '{' && x[i] == '}') || (s.top() == '[' && x[i] == ']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};