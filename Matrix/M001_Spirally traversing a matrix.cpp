#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;

        int left = 0, right = c - 1;
        int top = 0, down = r - 1;

        // denotes the direction of movement,
        int direction = 0; // 0 means right direction.

        while (top <= down && left <= right)
        {

            switch (direction)
            {

            case 0:
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }

                top++;
                direction = 1;
                break;

            case 1:
                for (int i = top; i <= down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }

                right--;
                direction = 2;
                break;

            case 2:
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }

                down--;
                direction = 3;
                break;

            case 3:

                for (int i = down; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }

                left++;
                direction = 0;
                break;
            }
        }

        return ans;
    }
};