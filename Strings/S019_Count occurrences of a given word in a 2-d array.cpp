#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    // DFS Solution.
    // Same character can be used in multiple strings.
    // we will change the visited character with '.', 
    // we can also use visited matrix.
    
    bool isValid( int row, int col, int rows, int cols, vector<vector<char> > &mat){
        
        if(row >= 0 && row < rows && col >= 0 && col < cols && mat[row][col] != '.' )  return true;
        return false;
        
    }
    
    int Helper(int row, int col, int ind , vector<vector<char> > &mat, string &target){
        
        // character does not match so return.
        if(mat[row][col] != target[ind]) return 0;
        
        // reached the end , so got the string.
        if(ind == target.size() -1){      
            return 1;
        }
        
        char ori = mat[row][col]; // keep track of original char,
        mat[row][col] = '.'; // mark it visited.
        
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, -1, 0, 1};
        
        int cnt = 0;
        
        for(int i =0 ; i < 4 ; i++){
            
            int nRow = row + rows[i];
            int nCol = col + cols[i];
            
            // if we can go to the new index.
            if(isValid(nRow, nCol, mat.size(), mat[0].size(), mat)) {
                
                cnt += Helper(nRow, nCol, ind + 1, mat, target);
                
            }
            
        }
        
        // mark it unvisited.    
        mat[row][col] = ori;
        return cnt;
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        int cnt = 0;
        
        for(int i = 0 ; i < rows; i++){
            
            for(int j = 0 ; j < cols; j++){
                
                cnt += Helper(i, j, 0 , mat, target);
                
            }
        }
        
        return cnt;
        
    }
};