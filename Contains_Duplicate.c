#include<stdio.h>
#include<stdlib.h>
void dup(int a[],int n){
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            printf("The Duplicate element:- %d\n",a[i]);
        }
    }
}
void insertion_Sort(int a[],int n){
    int key,j;
    for (int i = 1; i <=n-1; i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int a[]={1,2,3,4,2,3};
    int size=sizeof(a)/sizeof(a[0]);
    //insertion_Sort(a,size);
    dup(a,size);
    return 69;
}