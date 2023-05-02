class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        if(nums.size()==1){
            if(nums[0]==target){
                return {0,0};
            }
            else{
                return {-1,-1};

            }
        }
        for(int i=0;i<n;i++){
            
                if(nums[i]==target){
                    ans.push_back(i);
                    break;
                }


        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target){
                ans.push_back(j);
                break;

            }
        }
        if(ans.size()==0 or nums.size()==0){
            return{-1,-1};
        }

        return ans;
    }
};