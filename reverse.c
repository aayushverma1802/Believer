#include<stdio.h>
#include<stdlib.h>
void rvereseArray(int a[],int s,int end){
    int temp;
    while(s<end){
        temp=a[s];
        a[s]=a[end];
        a[end]=temp;
        s++;
        end--;
    }

}
void printArray(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    rvereseArray(arr, 0, n-1);
    printf("Reversed array is \n");
    printArray(arr, n);   
    return 0;
}