// --> Ideal for the Range Modification Problem 

//Famous Technique use to efficiently apply 
// range updates to an array.
// It helps to do multiple updates
// in constant time.
  
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //    Brute Force (TLE)
       
        // for (int i = 0; i < queries.size(); i++) {

        //     int start = queries[i][0];
        //     int end = queries[i][1];
        //     for (int k = start; k <=end; k++) {
        //         if (nums[k] - 1 >= 0) {
        //             nums[k] = nums[k] - 1;
        //         }
        //     }
            
        // }
        // for (auto& i : nums) {
        //     if (i != 0) {
        //         return false;
        //     }
        // }
        // return true;



    // Difference Array (OPTIMIZED)
    int n =nums.size();
    // Step-1 Make diff array using query
    vector<int>diff(n,0);
    for(auto &query:queries){
        int start=query[0];
        int end=query[1];
        int x=1;
        diff[start]+=x;
        if(end+1<n){
            diff[end+1]-=x;
        }

    }
    // Step-2 Find cumulative effect in each index
    vector<int>result(n,0);
    int cumSum=0;
    for(int i=0;i<n;i++){
        cumSum+=diff[i];
        result[i]= cumSum;

    }
    for(int i=0;i<n;i++){
        if(result[i]<nums[i]){
            return false;
        }
    }
    return true;
    }
};
