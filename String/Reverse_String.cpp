class Solution
{
public:
    void reverseString(vector<char> &a)
    {
        int n = a.size();
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(a[s], a[e]);
            s++;
            e--;
        }
    }
};