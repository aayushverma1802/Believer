class Solution
{
public:
    bool check(vector<int> &cc)
    {
        for (auto &i : cc)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size();
        int k = p.size();

        vector<int> ans;
        vector<int> cnt(26, 0);
        for (int i = 0; i < k; i++)
        {
            cnt[p[i] - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n)
        {
            cnt[s[j] - 'a']--;
            if (j - i + 1 == k)
            {
                if (check(cnt))
                {
                    ans.push_back(i);
                }
                cnt[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};