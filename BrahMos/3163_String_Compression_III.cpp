class Solution
{
public:
    string compressedString(string word)
    {
        int cnt = 1;
        string ans = "";
        for (int i = 0; i < word.size(); i++)
        {

            if (cnt >= 9)
            {
                string c = to_string(cnt);

                ans += c + word[i];
                cnt = 1;
            }
            else if (word[i] != word[i + 1])
            {
                string c = to_string(cnt);

                ans += c + word[i];
                cnt = 1;
            }
            else if (word[i] == word[i + 1])
            {
                cnt++;
            }
        }
        return ans;
    }
};