class Solution
{
public:
    // this question includes we need all the possible combos
    // this all possible combos give us the clear idea of the backtracking
    // Hence we will solve this question using the backtracking
    vector<string> ans;
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp)
    {
        if (idx >= digits.length())
        {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for (int i = 0; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp, mp);
            temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
        {
            return {};
        }
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp, m);
        return ans;
    }
};