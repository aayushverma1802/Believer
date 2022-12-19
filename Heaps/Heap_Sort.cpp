#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size = 0;
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete";
            return;
        }
        arr[1] = arr[size];
        size--;
        // Take roots to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size and arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size and arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n and arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n and arr[largest] < arr[right])
    {
        largest = right;
    }
    // To check if any Update happened !!

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void Heap_Sort(int arr[], int n)
{
    int size = n;

    while (size> 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    // printing the array
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // heap sort
    Heap_Sort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 69;
}
