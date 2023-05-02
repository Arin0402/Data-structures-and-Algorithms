#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/

// 1
// using bunary search
// O(log(r*c))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int low = 0;
        int high = r*c - 1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(matrix[ mid/c][mid%c] == target) return true;
            else if(matrix[ mid/c][mid%c] > target) high = mid - 1;
            else low = mid + 1;
        }
        
        return false;
            
        
    }
};
