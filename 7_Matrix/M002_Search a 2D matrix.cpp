#include <bits/stdc++.h>
using namespace std;

// Both are different
// https://leetcode.com/problems/search-a-2d-matrix/description/
// https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// https://www.youtube.com/watch?v=ZYpYur0znng

// 1
// naive traverse all the cells.
// O(N*M)

// 2
// Binary search for a single row
// leetcode
// O(n) + O(logM)
class Solution
{
public:
    bool binary(vector<int> &arr, int low, int high, int target)
    {

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int r = matrix.size();
        int c = matrix[0].size();

        // find the row which contins the target.
        // if the last value of row is greater than or equal to the target,
        // then target lies in that row.
        for (int i = 0; i < r; i++)
        {

            if (target <= matrix[i][c - 1])
            {
                // apply binary seacrh to that row.
                return binary(matrix[i], 0, c - 1, target);
            }
        }

        return false;
    }
};

// 3
// leetcode
// applying binary search on whole matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();

        int low =0;
        int high = r*c - 1;

        while(low <= high){

            int mid = (low + high)/2;

            if(matrix[mid/c][mid%c] == target) return true;
            else if (matrix[mid/c][mid%c] > target) high = mid -1;
            else low = mid + 1;

        }

        return false;  
    }
};

// 4
// gfg
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    
	    int i = 0, j = M - 1;
	    
	    while(i < N && j >= 0){
	        
	        
	        if(mat[i][j] == X) return 1;
	        else if (mat[i][j]  < X) i++;
	        else j--;
	        
	    }
	    
	    return 0;
        	    
	    
	}
};
