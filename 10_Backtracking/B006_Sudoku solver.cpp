#include <bits/stdc++.h>
using namespace std;

#define N 9

// TC - O(9^(n*n)).
class Solution
{
public:
    // Function to find a solved Sudoku.

    bool check(int row, int col, int val, int grid[N][N])
    {

        for (int i = 0; i < 9; i++)
        {
            if (grid[row][i] == val)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (grid[i][col] == val)
                return false;
        }

        // square
        row = 3*(row/3);
        col = 3*(col/3);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[row + i][col + j] == val) return false;
            }
        }
        return true;
    }

    bool solve(int row, int col, int grid[N][N])
    {

        if (row == N)
            return true;
        if (col == N)
            return solve(row + 1, 0, grid);
        if (grid[row][col] != 0)
            return solve(row, col + 1, grid);

        for (int k = 1; k <= 9; k++)
        {

            if (check(row, col, k, grid))
            {

                grid[row][col] = k;
                if (solve(row, col + 1, grid))
                    return true;
                grid[row][col] = 0;
            }
        }

        return false;
    }

    bool SolveSudoku(int grid[N][N])
    {

        return solve(0, 0, grid);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};
