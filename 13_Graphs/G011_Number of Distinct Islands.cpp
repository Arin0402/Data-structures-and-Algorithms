#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // TC - O(n.m) + O(n.m.4) + log(n.m) , log is for set.

    void dfs(int row, int col, vector<pair<int, int>> &vec, vector<vector<bool>> &vis, vector<vector<int>> &grid, int row0, int col0, int r, int c)
    {

        vis[row][col] = true;
        vec.push_back({row - row0, col - col0}); // subtract the base cordinates form the cordinate.

        int rows[4] = {0, 1, 0, -1};
        int cols[4] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rows[i];
            int ncol = col + cols[i];

            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {

                dfs(nrow, ncol, vec, vis, grid, row0, col0, r, c);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> vis(r, vector<bool>(c, false)); // visited array.
        set<vector<pair<int, int>>> st;                      // set to store the size of different islands.

        // O(n.m)
        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < c; j++)
            {

                if (grid[i][j] == 1 && !vis[i][j])
                {

                    vector<pair<int, int>> vec; // insert all coordinates of a island.(shape)

                    // O(n.m.4)
                    dfs(i, j, vec, vis, grid, i, j, r, c);

                    st.insert(vec); // insert shape into set.
                }
            }
        }

        return st.size();
    }
};
