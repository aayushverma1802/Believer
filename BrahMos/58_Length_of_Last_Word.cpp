class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        reverse(begin(s), end(s));
        int cnt = 0;
        int sp = 0;

        // 1) Add count and spaces
        // then subtract the space and print the ans

        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
            {
                while (s[i] == ' ')
                {
                    sp++;
                    cnt++;
                    i++;
                    cout << i << " b " << sp;
                }
            }
            if (s[i] != ' ')
            {
                cnt++;
            }
            if (s[i] == ' ')
            {
                return cnt - sp;
            }
        }
        return cnt - sp;

        // 2)Instead of counting the spaces just move the pointer
        // the place where we first encounter the char of the last word
        // insuring that all the spaces are ignored and the pointer has moved
        // to the desired location

        //         for (int i = 0; i < s.size(); i++) {
        //     if (i == 0) {
        //         while (s[i] == ' ') {
        //             i++;
        //         }
        //     }
        //     if (s[i] != ' ') {
        //         cnt++;
        //     }
        //     if (s[i] == ' ') {
        //         return cnt;
        //     }
        // }
        // return cnt;
    }
};