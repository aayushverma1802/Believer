#include <stdio.h>
// Traversal of the Array
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// Bubble Sort Function
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1); // No. of passes
        for (int j = 0; j < n - 1 - i; j++)           // No. of comparison
        {
            // Swapping the Numbers
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
// Optimized Funtion of Bubble Sort
void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0; // 0 means Unsorted && 1 means Sorted
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0; // If not sorted again run
            }
        }
        if (isSorted)
        {
            // If Sorted stop.
            return;
        }
    }
}
int main()
{
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = 11;
    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);
    printf("\n");
    printf("Optimized Bubble Sort:- \n");
    bubbleSortAdaptive(A, n);
    printArray(A, n);
    return 69;
}
