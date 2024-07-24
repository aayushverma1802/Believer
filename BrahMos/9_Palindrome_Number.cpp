class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        string s = to_string(x);
        reverse(s.begin(), s.end());

        // long long int ch=stoi(s);
        // ^
        // |
        //             using this line can cause
        //             terminate called after throwing an instance of
        //             'std::out_of_range'
        //   what():  stoi
        return to_string(x) == s;
    }
};