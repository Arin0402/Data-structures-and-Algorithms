#include <bits/stdc++.h>
// https://www.codingninjas.com/codestudio/problems/knight-tour_1170518?leftPanelTab=0

bool check(int row, int col, int n, int m, vector<vector<int>> &board)
{

    if (row >= 0 && row < n && col >= 0 && col < m && board[row][col] == -1)
        return true;

    return false;
}
bool helper(int row, int col, int countVisited, int n, int m, vector<vector<int>> &board)
{

    // total number of visited cells are equal to n*m.
    if (countVisited >= n * m)
        return true;

    int rows[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int cols[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++)
    {
        int nrow = row + rows[i];
        int ncol = col + cols[i];

        if (check(nrow, ncol, n, m, board))
        {

            board[nrow][ncol] = countVisited;
            if (helper(nrow, ncol, countVisited + 1, n, m, board))
                return true;
            board[nrow][ncol] = -1;
        }
    }
    return false;
}
vector<vector<int>> knightTour(int n, int m)
{

    vector<vector<int>> board(n, vector<int>(m, -1));

    board[0][0] = 0; // mark the first place.

    int countVisited = 1; // for first position.
    if (helper(0, 0, countVisited, n, m, board))
        return board;

    vector<vector<int>> ans(n, vector<int>(m, -1));
    return ans;
}