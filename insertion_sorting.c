#include<stdio.h>
void printArr(int a[],int n){
    for (int k = 0; k < n; k++){
        printf("%d ",a[k]);
    }
    printf("\n");
}
void inseertion_sort(int a[],int n){
    int j,key;
    for (int i=1;i<=n-1;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={12,54,65,7,23,9}; 
    int n=6;
    inseertion_sort(a,n);
    printArr(a,n);
    return 69;
}