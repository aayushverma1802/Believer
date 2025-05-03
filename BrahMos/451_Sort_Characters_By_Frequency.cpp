class Solution
{
public:
    string frequencySort(string s)
    {
        priority_queue<pair<int, char>> pq;
        map<char, int> m;

        for (auto &i : s)
        {
            m[i]++;
        }

        for (auto &i : m)
        {
            pq.push({i.second, i.first});
        }

        string ans = "";
        // Append characters by frequency
        while (!pq.empty())
        {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            ans += string(freq, ch); // repeat character `freq` times
        }

        return ans;
    }
};
