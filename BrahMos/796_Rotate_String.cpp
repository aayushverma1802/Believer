class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        bool flag = false;
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            char t = s[n - 1];
            temp = s;
            for (int j = 0; j < n - 1; j++)
            {
                s[j + 1] = temp[j];
            }
            s[0] = t;
            temp = s;
            cout << s << " ";
            if (s == goal)
                return true;
        }
        return flag;
    }
};