#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1


class Solution
{

public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        // return distance matrix
        vector<vector<int>> dis(n, vector<int>(m, 0));  

        // visited matrix
        vector<vector<bool>> vis(n, vector<bool>(m, false)); 

        // {{i, j}, val}
        queue<pair<pair<int, int>, int>> q; 

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                { // insert all 1's in the queue

                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};

        while (!q.empty())
        {

            int r = q.front().first.first;
            int c = q.front().first.second;

            int val = q.front().second;

            q.pop();
            dis[r][c] = val; // set the distance. ( for 1 , the distance is zero)

            for (int i = 0; i < 4; i++)
            {

                int nrow = r + rows[i];
                int ncol = c + cols[i];

                // check for 0;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && vis[nrow][ncol] == false)
                {

                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, val + 1}); // update the value for the next by 1
                }
            }
        }

        return dis;
    }
};