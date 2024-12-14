class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal)
                return true;
        }
        return false;
    }
};
/* 
Rotate stl format 
 rotate(s.begin(), s.begin() + 1, s.end());

 (starting range, which position will become starting range,end of the range)


 this stl uses KMP which we had studied in DAA
 TC O(n)
 SC O(n)
*/