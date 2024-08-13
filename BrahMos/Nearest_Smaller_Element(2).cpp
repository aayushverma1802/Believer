vector<int> Solution::prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> a(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (!s.empty() && s.top() >= curr)
        {
            s.pop();
        }
        if (s.empty())
        {
            a[i] = -1; // No previous smaller element
        }
        else
        {
            a[i] = s.top(); // Previous smaller element found
        }
        s.push(curr);
    }
    return a;
}
