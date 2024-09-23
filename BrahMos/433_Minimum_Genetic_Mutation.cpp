class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        set<string> s(bank.begin(), bank.end());
        queue<pair<int, string>> q;
        vector<char> k = {'A', 'C', 'G', 'T'};
        q.push({0, startGene});
        int ans = INT_MIN;
        while (q.empty() == false)
        {
            string n = q.front().second;
            int c = q.front().first;
            q.pop();
            if (n == endGene)
                return c; // Return the count when reaching endGene

            for (int i = 0; i < n.size(); i++)
            {
                char org = n[i];
                for (auto j : k)
                {
                    n[i] = j;
                    if (s.find(n) != s.end())
                    {
                        q.push({c + 1, n});
                        s.erase(n);
                    }
                }
                n[i] = org;
            }
        }
        return -1;
    }
};