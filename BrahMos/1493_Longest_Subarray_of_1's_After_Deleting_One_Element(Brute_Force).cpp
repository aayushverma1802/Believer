class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return nums;
        }
        else if (k > nums.size() / 2)
        {
            vector<int> temp(nums.size(), -1);
            return temp;
        }
        int n = nums.size();
        vector<int> ans(n, -1);
        int i = 0;
        long long int sum_temp = 0;
        for (int j = 0; j < n; j++)
        {
            sum_temp += nums[j];
            if (j - i + 1 == k * 2 + 1)
            {

                ans[i + k] = sum_temp / (k * 2 + 1);
                suclass Solution{
                    public :
                        int longestSubarray(vector<int> & nums){
                            int n = nums.size();
                int prev = 0;
                int maxi = 0;
                int cnt = 0;
                int j = 0, i = 0;
                int flg = 0;
                // for(auto i:nums){
                //     if(i!=0 and i==n)
                //         flg=1;
                // }
                // if(flg)
                // return n-1;
                int range = 0;
                while (i < n)
                {

                    if (nums[i] == 0)
                    {
                        prev = cnt;
                        cnt = 0;
                        flg = true;
                    }
                    else if (nums[i] == 1)
                    {
                        cnt++;
                    }

                    maxi = max(maxi, prev + cnt);

                    i++;
                }
                return flg == true ? maxi : n - 1;
            }
        };
        m_temp -= nums[i];
        i++;
    }
} return ans;
}
}
;