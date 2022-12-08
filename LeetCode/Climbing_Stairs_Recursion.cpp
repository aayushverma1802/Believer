class Solution {
public:
int j(int n , int i){
    if(n<i){
        return 0;
        }
    if(i==n){
        return 1;
    }
     return (j(n,i+1) +j(n,i+2));
}
    int climbStairs(int n) {
        int ans=j(n,0);
        return ans;
    }
};