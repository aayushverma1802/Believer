class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int sum = 0;
        // My approach
        //  for(int i=0;i<nums.size();i++){
        //      sum+=nums[i];
        //      maxi=max(maxi,sum);
        //      if (sum<0 ){
        //          sum=0;
        //      }

        // }
        // Brute force
        // for (int i = 0; i < nums.size(); i++) {
        //     sum += nums[i];
        //     maxi = max(maxi, sum);
        //     if (sum > maxi) {
        //         maxi = sum;
        //     }
        //     if (sum < 0) {
        //         sum = 0;
        //     }
        // }
        // Most Optimal Approach
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};