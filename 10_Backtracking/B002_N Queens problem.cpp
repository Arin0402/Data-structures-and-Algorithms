#include <bits/stdc++.h>
using namespace std;

///  (n-1) + (col - row).

// 1
// O(n!)*O(n^2) but why ?

// The brute-force approach to solving the problem involves examining all possible permutations of the queens on the board, and then checking if each permutation is a valid solution.

// There are n! possible permutations of the n queens on the board, where n! is the factorial of n. This is because there are n choices for the position of the first queen, n-1 choices for the position of the second queen (since it cannot be in the same row or column as the first queen), n-2 choices for the position of the third queen (since it cannot be in the same row or column as the first two queens), and so on, down to 1 choice for the position of the last queen.

// Reason for n^2 -> since each time we are checking if the position of the queen is valid or not by traversing left and diagonally top and bottom

// using extra space
class Solution
{
public:
    bool check(int row, int col, int n, vector<vector<int>> &board)
    {

        int duprow = row;
        int dupcol = col - 1;

        // left;
        while (dupcol >= 0)
        {
            if (board[row][dupcol] == 1)
                return false;
            dupcol--;
        }

        duprow = row - 1;
        dupcol = col - 1;

        // upper
        while (dupcol >= 0 && duprow >= 0)
        {
            if (board[duprow][dupcol] == 1)
                return false;
            duprow--;
            dupcol--;
        }

        // lower
        duprow = row + 1;
        dupcol = col - 1;

        while (dupcol >= 0 && duprow < n)
        {
            if (board[duprow][dupcol] == 1)
                return false;
            duprow++;
            dupcol--;
        }

        return true;
    }

    void helper(int col, int n, vector<int> temp, vector<vector<int>> &board, vector<vector<int>> &ans)
    {

        if (col == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (check(row, col, n, board))
            {

                board[row][col] = 1;
                temp.push_back(row + 1);

                helper(col + 1, n, temp, board, ans);

                temp.pop_back();
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {

        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;

        vector<int> temp;

        helper(0, n, temp, board, ans);

        return ans;
    }
};

// 2
// O(n)
// without using  extra space.
class Solution
{
public:
    void helper(int col, int n, vector<int> &temp, vector<int> &left, vector<int> &upper, vector<int> &lower, vector<vector<int>> &ans)
    {

        if (col == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {

            if (left[row] == 0 && lower[row + col] == 0 && upper[(n - 1) + (col - row)] == 0)
            {

                left[row] = 1;
                lower[row + col] = 1;
                upper[(n - 1) + (col - row)] = 1;
                temp.push_back(row + 1);

                helper(col + 1, n, temp, left, upper, lower, ans);

                temp.pop_back();
                left[row] = 0;
                lower[row + col] = 0;
                upper[(n - 1) + (col - row)] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {

        vector<vector<int>> ans;

        vector<int> left(n, 0);
        vector<int> upper(2 * n - 1, 0);
        vector<int> lower(2 * n - 1, 0);

        vector<int> temp;

        helper(0, n, temp, left, upper, lower, ans);

        return ans;
    }
};
