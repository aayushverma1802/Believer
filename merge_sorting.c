//Including the header file
#include<stdio.h>
//Use to traverse the array
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void merge(int a[],int low,int mid,int high){

    int B[100];//Another array to store elements
    int i=low;//"i" stores the low of the array
    int j=mid+1;//"j" will help in partition of the array
    int k=low; 
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            B[k]=a[i];//Inset array "A" elements to "B"
            i++;
            k++;
        }
        else{
            B[k]=a[j];
            j++;
            k++;
        }
    }
    /*Separate while just in case the array from 
    low to mid
    or 
    mid+1 to high
    gets filled first*/
    while(i<=mid){
        B[k]=a[i];
        k++;
        i++;

    }
    while(j<=high){
        B[k]=a[j];
        k++;
        j++;
    }

    for(int i=low;i<=high;i++){
        a[i]=B[i];
    }
}
void mergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        //recursion
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int A[] = {90, 14, 68, 73, 24, 19, 34};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 69;
}
