class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(begin(g), end(g));
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int i = 0, j = 0;
        while (i < n and j < m)
        {
            if (g[i] <= s[j])
            {
                i++;
            }
            j++;
        }
        return i;
    }
};