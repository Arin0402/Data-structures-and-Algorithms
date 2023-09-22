#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(int row, int col, vector<vector<char>> &grid ){
        
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
            return true;
        
        return false;
        
    }
    
    bool checkIfPresent(int row, int col, int ind, int direc, int originRow, int originCol, vector<vector<int>> &ans, vector<vector<char>> &grid, string &word ){
            
        // word is present.        
        if(ind == word.size()){
            ans.push_back({originRow, originCol});
            return true;
        }

        // Only required to get the direction.
        int rows[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
        int cols[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        int nrow = row + rows[direc];
        int ncol = col + cols[direc];
        
        if(isValid(nrow, ncol, grid) && grid[nrow][ncol] == word[ind] ){
            
            bool found = checkIfPresent(nrow, ncol, ind + 1, direc, originRow, originCol, ans, grid, word);
            // whole word is present in this direction.
            if(found) return true;
        }
        // word is not present in this direction.
        else return false;
        
    }
    
    bool Helper(int row , int col , int ind , vector<vector<int>> &ans, vector<vector<char>> &grid, string &word){
        
        // if size of word is one, then return,
        if(word.size() == 1){
            ans.push_back({row, col});
            return true;
        }
        
        // eight directions.
        int rows[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
        int cols[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int i = 0; i < 8; i++){
            
            int nrow = row + rows[i];
            int ncol = col + cols[i];
            
            // check in which direction we find the second character of the word.
            
            if(isValid(nrow, ncol, grid) && grid[nrow][ncol] == word[ind]){
                
                // Now we will check for the whole word in this direction only.
                // i represent the direction.
                bool found = checkIfPresent(nrow, ncol, ind + 1, i , row, col, ans, grid, word);
                
                // Whole word is present in that direction.
                // No need to try other directions as stated in the question.
                if(found) return true;
                        
            }
            
        }
        
        return false;
            
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans;
        
        for(int i =0 ; i < n; i++){
            for(int j =0 ; j < m; j++){
                
                // if the character matches with the starting char of the string.
                if(grid[i][j] == word[0])
                    Helper(i, j, 1 , ans, grid, word);
                
            }
        }
	    
	    
	    return ans;
	    
	}
};