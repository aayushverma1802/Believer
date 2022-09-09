#include <stdio.h>
void bubbleSort(int *a, int n)
{
    int x = 12, count = 0, c = 0;
    int i = 0;
    // int j=n-1;
    // int k=i+1;
    for (i = 0; i < n - 2; i++)
    {
        int j = n - 1;
        int k = i + 1;
        while (k < j)
        {
            if ((a[i] + a[k] + a[j]) < (x))
            {

                c += j - k;
                count++;
                k++;
            }
            else
            {
                j--;
            }
        }
    }
    printf("%d\n", count);
    printf("%d", c);
}
void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
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
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

// Using sorting to Sort First in above fucntion

void Countre(int a[], int n)
{
    int x = 6;
    // Element to compare
    int count = 0;
    int i = 0;
    int j = n;
    int k = i + 1;
    for (i = 0; i < n - 2; i++)
    {
        while (i < j)
        {
            if ((a[i] + a[k] + a[j]) < (x))
            {
                count++;
            }
            else
            {
                j--;
            }
        }
    }
    printf("%d", count);
}
int main()
{
    int A[] = {1, 3, 4, 5, 7};
    int n = 5;
    // printArray(A, n);
    bubbleSort(A, n);
    // printArray(A, n);
    printf("\n");
    // Countre(A,n);

    return 0;
}
