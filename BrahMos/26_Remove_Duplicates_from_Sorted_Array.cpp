class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // Brute Force
        //  set<int>st(nums.begin(),nums.end());
        //  nums.clear();
        //  for(auto i:st){
        //      nums.push_back(i);
        //  }
        //  return st.size();

        // Two Pointer
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[i] != nums[j])
            {
                i++;

                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};