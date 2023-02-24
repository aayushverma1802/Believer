//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    // Function to find a solved Sudoku.
    bool isSafe(int row, int col, int bord[N][N], int val)
    {
        int n = N;
        for (int i = 0; i < n; i++)
        {
            if (bord[row][i] == val)
            {
                return false;
            }
            if (bord[i][col] == val)
            {
                return false;
            }
            if (bord[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(int bord[N][N])
    {
        int n = N;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (bord[row][col] == 0)
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (isSafe(row, col, bord, val))
                        {
                            bord[row][col] = val;
                            bool aagesoloution = solve(bord);
                            if (aagesoloution)
                            {
                                return true;
                            }
                            else
                            {
                                bord[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])
    {
        solve(grid);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        int n = N;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends