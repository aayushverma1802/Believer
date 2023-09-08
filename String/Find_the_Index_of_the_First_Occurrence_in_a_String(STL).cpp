class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // int n=haystack.length();
        // int m=needle.length();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if( haystack[i]==needle[j] ){
        //             ans.push_back(j);
        //         }
        //         if( j!=m and haystack[i]!=needle[j] ){
        //             ans[0]=-1;
        //         }

        //     }
        // }
        // return  ans[0];
        return haystack.find(needle);
    }
};