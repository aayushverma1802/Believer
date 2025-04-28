class Solution {
public:
    string Removesubstr(string& s, string& cond) {
        stack<char> st;
        string temp;
        for (auto& i : s) {
            if (i == cond[1] and st.empty() == false and st.top() == cond[0]) {
                st.pop();
            } else {
                st.push(i);
            }
        }
        while (st.empty() == false) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        string maxstr = x >= y ? "ab" : "ba";
        string minstr = x <y ? "ab" : "ba";
        int n = s.size();

        int ans = 0;
        // First pass
        string fp = Removesubstr(s, maxstr);
        int fpl = n - fp.length();
        ans += (fpl / 2) * max(x,y);
        // Second pass
        string sp = Removesubstr(fp, minstr);
        int spl = fp.length()-sp.length();
        ans += (spl / 2) * min(x,y);

        return ans;
    }
};