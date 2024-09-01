class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> s;
        for (auto i : num)
        {
            while (s.empty() == false and k > 0 and s.top() > i)
            {
                s.pop();
                k--;
            }
            // Separate conditions for pushing the digit onto the stack
            if (s.empty())
            {
                // If stack is empty, only push non-zero digits to avoid leading zeros
                if (i != '0')
                {
                    s.push(i);
                }
            }
            else
            {
                // If stack is not empty, push the digit onto the stack
                s.push(i);
            }
        }
        while (k != 0 and s.empty() == false)
        {
            s.pop();
            k--;
        }
        if (s.empty())
        {
            return "0";
        }
        string ans;
        while (s.empty() == false)
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};