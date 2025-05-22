class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // Brute(TLE)
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]==nums[j] and abs(i-j)<=k){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        // OPTIMIZED
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end() and abs(m[nums[i]] - i) <= k)
            {
                return true;
            }
            else
            {
                // m.insert({nums[i],i});
                m[nums[i]] = i;
            }
        }
        return false;
    }
};