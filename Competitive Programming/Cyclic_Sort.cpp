#include <iostream>
#include <vector>
#include <utility>
// Cyclic Sort
// Cyclic Sort is an in-place sorting algorithm that is useful when numbers are in a range from 1 to N.
// It works by placing each number at its correct index.

// Key Idea
// If an element is not at its correct position, swap it with the element at its correct index.
// Keep swapping until the current number is in the right place.
// Repeat for all elements.

// Time Complexity
// Best, Average, Worst Case: O(N)
// Space Complexity: O(1) (In-Place Sorting)
using namespace std;
class Cyclic_Sort
{
public:
    vector<int> Solver(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int correct_pos = nums[i] - 1;
            if (nums[i] != nums[correct_pos])
            {
                swap(nums[correct_pos], nums[i]);
            }
            else
            {
                i++;
            }
        }
        return nums;
    }
};
int main()
{
    Cyclic_Sort obj;
    vector<int> nums;
    nums={5, 3, 1, 4, 2};
    // nums = {1 ,5 ,3 ,2};

    vector<int> ans = obj.Solver(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}