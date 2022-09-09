#include<stdio.h>
#include<stdlib.h>
struct pair{
    int min;
    int max;
};
struct pair getminmax(int a[],int n){
    struct pair minmax;
    if(n==1){
        minmax.min=a[0];
        minmax.max=a[0];
        return minmax;
    }
    if(a[0]>a[1]){
        minmax.max=a[0];
        minmax.min=a[1];
    }
    else{
        minmax.min=a[0];
        minmax.max=a[1];
    }
    for(int i=2;i<n;i++){
        if(a[i]>minmax.max){
            minmax.max=a[i];
         //   minmax.min=a[i+1];
        }
        else if(a[i]<minmax.min){
            minmax.min=a[i];

        }
    }
    return minmax;

}
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    struct pair minmax = getminmax (arr, arr_size);
    printf("nMinimum element is %d\n", minmax.min);
    printf("nMaximum element is %d\n", minmax.max);
    //getchar();
} 