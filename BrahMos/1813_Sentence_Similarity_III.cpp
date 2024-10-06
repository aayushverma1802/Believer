class Solution
{
public:
    bool areSentencesSimilar(string s1, string s2)
    {
        stringstream ss1(s1);
        stringstream ss2(s2);
        string token = "";
        deque<string> q1, q2;
        while (ss1 >> token)
        {
            q1.push_back(token);
        }
        token.clear();
        while (ss2 >> token)
        {
            q2.push_back(token);
        }
        while (q1.empty() == false and q2.empty() == false)
        {
            if (q1.front() != q2.front())
            {
                break;
            }
            q1.pop_front();
            q2.pop_front();
        }
        while (q1.empty() == false and q2.empty() == false)
        {
            if (q1.back() != q2.back())
            {
                break;
            }
            q1.pop_back();
            q2.pop_back();
        }
        return q1.empty() or q2.empty();
    }
};