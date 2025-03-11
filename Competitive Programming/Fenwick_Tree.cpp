#include <iostream>
#include <vector>
using namespace std;
class FenwickTree
{
    vector<int> BIT;
    int N;

public:
    FenwickTree(int size)
    {
        N = size;
        BIT.assign(N + 1, 0);
    }
    void update(int index, int value)
    {
        while (index <= N)
        {
            BIT[index] += value;
            index += index & (-index);
        }
    }
    int query(int index)
    {
        int sum=0;
        while (index>0)
        {
            sum+= BIT[index];
            index -= index & (-index);
        }
        return sum;
    }
};
int main(){
    int N=5;
    vector<int>arr={1,2,3,4,5};
    FenwickTree obj(N);
    for(int i=0;i<N;i++){
        obj.update(i+1,arr[i]);
    }
    cout<<"Prefix sum at index 3"<<obj.query(3)<<endl;
    obj.update(2,2);
    cout<<"After Update "<<obj.query(3)<<endl;
    return 0;

}