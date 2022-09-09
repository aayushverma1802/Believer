
#include<stdio.h>
void printArray(int *A, int n){
    for (int i = n-1; i >=0; i--)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void selectionSort(int *A, int n){
    int indexOfMin, temp;
   // printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}
void checker(int a[],int n){
    int isDone=0;
    for (int i=0;i<n;i++){
        if (a[i]==100){
            isDone+=1;
        }
        else{
            isDone+=0;
        }

    }
    if(isDone>0){
        printf("Searching element found\n");
    }
    else{
        printf("Not Found");
    }
}
int main(){
    int A[] = {75,55,85,100,105,65,95,250,200,210};
    int n = sizeof(A)/sizeof(A[0]);
   // printArray(A, n);
    selectionSort(A, n);
    checker(A,n);
    printArray(A, n);
    return 69;
}