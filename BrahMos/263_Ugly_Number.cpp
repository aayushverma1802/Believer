class Solution
{
public:
    bool isUgly(int n)
    {
        // 1)
        // if(n==0){
        //     return false;
        // }
        // if(n==1){
        //     return true;
        // }
        // while(n%5==0){
        //     n/=5;
        // }
        // while(n%3==0){
        //     n/=3;
        // }
        // while(n%2==0){
        //     n/=2;
        // }
        // return n==1;

        // 2)
        if (n == 0)
        {
            return false;
        }
        int arr[] = {2, 3, 5};
        for (auto i : arr)
        {
            while (n % i == 0)
            {
                n /= i;
            }
        }
        return n == 1;
    }
};