class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char>st;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(st.empty()==true or st.top()==s[i]){
                st.push(s[i]);
            }
            if(st.top()!=s[i]){
                st.pop();      
            }
               if(st.empty()){
                count++;}
   
        }
        return count;
        
    }
};