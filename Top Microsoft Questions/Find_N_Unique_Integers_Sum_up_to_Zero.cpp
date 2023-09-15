class Solution {
public:
    vector<int> sumZero(int n) {
        int x=n/2;
        vector<int>ans;
        while(0<x){
            ans.push_back(x);
            ans.push_back(-x);
            x--;
        }
        if(n&1){
            //if the value of the n is odd;
            ans.push_back(0);
        }
        return ans;
    }
};