#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(n^3)
    void shortest_distance(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int k = 0; k < n; k++)
        {

            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][k] == -1 || matrix[k][j] == -1)
                        continue; // other path does not exist.

                    if (matrix[i][j] == -1)
                        matrix[i][j] = matrix[i][k] + matrix[k][j]; // direct path does not exist so other path will be minimum.

                    else if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
};