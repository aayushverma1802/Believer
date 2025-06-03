class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int maxi=0;
        int cnt=0;
        int j=0,i=0;
        int flg=0;
        // for(auto i:nums){
        //     if(i!=0 and i==n)
        //         flg=1;
        // }
        // if(flg)
            // return n-1;
            int range=0;
        while(i<n){
            
            if(nums[i]==0){
                prev=cnt;
                cnt=0;
                flg=true;
            }
            else if(nums[i]==1){
                cnt++;
         
            }

                maxi=max(maxi,prev+cnt);

            i++;
        }
        return flg==true?maxi:n-1;
    }
};
