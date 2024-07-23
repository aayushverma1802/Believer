class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        int *a = new int[n]; // Allocate array dynamically

        // Copy original array to 'a'
        for (int i = 0; i < n; i++)
        {
            a[i] = arr[i];
        }

        // Perform rotation
        for (int j = 0; j < d; j++)
        {
            int k = a[0]; // Save the first element
            for (int i = 0; i < n - 1; i++)
            {
                a[i] = a[i + 1]; // Shift elements to the left
            }
            a[n - 1] = k; // Move the saved first element to the last position

            // Copy the rotated array back to the original array
            for (int i = 0; i < n; i++)
            {
                arr[i] = a[i];
            }
        }

        delete[] a; // Free dynamically allocated memory
    }
};