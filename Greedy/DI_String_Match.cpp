class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int i = 0;
        int j = s.length();
        vector<int> v;
        for (int k = 0; k < s.size(); k++)
        {
            if (s[k] == 'I')
            {
                v.push_back(i);
                i++;
            }
            else
            {
                v.push_back(j);
                j--;
            }
        }
        v.push_back(j--);
        return v;
    }
};