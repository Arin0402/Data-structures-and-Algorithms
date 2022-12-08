#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

// 1
// using extra space
// create another matrix of n x n.
// copy the elements into it and return.

// 2
// withuot extra space.
// TC - O(N^2)

// This is for anti clock wise.

// first find the transpose of the matrix and then reverse each row.
class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int top = 0;
        int bot = n - 1;

        // swap the top rows with the bottom rows.
        while (top < bot)
        {

            for (int i = 0; i < n; i++)
            {

                swap(matrix[top][i], matrix[bot][i]);
            }
            top++;
            bot--;
        }
    }
};

// NOTE - if clock wise rotation then, reverse each row of the matrix after transpose.
