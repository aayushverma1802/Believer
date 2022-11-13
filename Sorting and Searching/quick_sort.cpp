//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int A[], int low, int high)
    {
        // code here
        int partitionIndex;
        if (low < high)
        {
            partitionIndex = partition(A, low, high);
            quickSort(A, low, partitionIndex - 1);
            quickSort(A, partitionIndex + 1, high);
        }
    }

public:
    int partition(int A[], int low, int high)
    {
        // Your code here
        int pivot = A[low];
        int i = low + 1;
        int j = high;
        int temp;
        do
        {
            while (A[i] <= pivot)
            {
                i++;
            }
            while (A[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        } while (i < j);

        temp = A[low];
        A[low] = A[j];
        A[j] = temp;
        return j;
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000], n, T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        Solution ob;
        ob.quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends