class Solution
{
public:
    string simplifyPath(string path)
    {
        string token = "";
        stringstream ss(path);
        stack<string> st;
        while (getline(ss, token, '/'))
        {
            if (token == "" or token == ".")
            {
                continue;
            }
            if (token != "..")
            {
                st.push(token);
            }
            else if (st.empty() == false)
            {
                st.pop();
            }
        }
        if (st.empty() == true)
        {
            return "/";
        }
        string result = "";
        while (st.empty() == false)
        {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};