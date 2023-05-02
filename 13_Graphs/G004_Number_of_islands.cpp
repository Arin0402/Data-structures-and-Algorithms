// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

// using BFS traversal (i.e Iterative method. Basically it is a recursion problem and nothing to do with graph)
// TC  - O(N^2) + O(N^2)*9 = O(N^2)
// can be done without using visited matrix by making changes in the original grid. Just replace the visited and zero node with 2.
class Solution1
{
public:
    void bfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {

        vis[row][col] = true; // mark this cell as visited.

        queue<pair<int, int>> q; // to store the neighbours which are land.
        q.push({row, col});

        int r = grid.size();
        int c = grid[0].size();

        while (!q.empty())
        {

            auto p = q.front();
            q.pop();

            // To check all the eight neighbours.
            for (int delrow = -1; delrow <= 1; delrow++)
            { // O(N^2)*9

                for (int delcol = -1; delcol <= 1; delcol++)
                {

                    int nrow = p.first + delrow; // check for the neighbours standing on the current cell;
                    int ncol = p.second + delcol;

                    if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                    { // validity check

                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int r = grid.size();    // number of rows.
        int c = grid[0].size(); // number of columns

        vector<vector<bool>> vis(r, vector<bool>(c, false)); // visited matrix.

        int count = 0; // count of islands.

        for (int i = 0; i < r; i++)
        { // O(N^2)

            for (int j = 0; j < c; j++)
            {

                if (grid[i][j] == '1' && !vis[i][j])
                { // if the cell is land and not visited yet.

                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};

// DFS Traversal (Recursive soolution)
class Sloution2
{
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();

        for (int delrow = -1; delrow <= 1; delrow++)
        {

            for (int delcol = -1; delcol <= 1; delcol++)
            {

                int nrow = row + delrow;
                int ncol = col + delcol;

                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = true;
                    dfs(nrow, ncol, vis, grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false)); // visited array.

        int count = 0;

        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < c; j++)
            {

                if (grid[i][j] == '1' && !vis[i][j])
                {

                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};