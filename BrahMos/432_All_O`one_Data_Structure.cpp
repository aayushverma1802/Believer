class AllOne
{
public:
    unordered_map<string, int> m;
    AllOne() {}

    void inc(string key)
    {
        // Direct increment or insertion using operator[]
        m[key]++;
    }

    void dec(string key)
    {
        auto it = m.find(key);
        if (it != m.end())
        {
            if (--it->second == 0)
            {
                m.erase(it);
            }
        }
    }

    string getMaxKey()
    {
        int maxi = INT_MIN;
        string ans = "";
        for (const auto &i : m)
        {
            if (i.second > maxi)
            {
                maxi = i.second;
                ans = i.first;
            }
        }
        return ans;
    }

    string getMinKey()
    {
        int mini = INT_MAX;
        string ans = "";
        for (const auto &i : m)
        {
            if (i.second < mini)
            {
                mini = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
