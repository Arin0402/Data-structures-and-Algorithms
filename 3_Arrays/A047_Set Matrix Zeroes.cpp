#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/

// easy 

// 1
// mark with -1

// 2
// use two arrays for row and column respectively

// 3
// without using extra space
// My solution
// Striver's solution is complicated


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int n = matrix.size();
        int m = matrix[0].size();


        bool TopLeftCell = false; // for matrix[0][0], check for if zero or not.
        bool firstRow = false; // if first row contains any zero or not
        bool firstCol = false; // if first col contains any zero or not

        // the top left cell contains zero
        // so the first row and the first col will be converted to zero
        if(matrix[0][0] == 0) TopLeftCell = true;

        // no need to check if the top left cell contains 0
        if(TopLeftCell == false){
            
            // check for first row if it contains any zero or not
            for(int j = 1; j < m; j++){
                if(matrix[0][j] == 0){

                    firstRow = true;
                    break;
                }
            }

            // check for first col if it contains any zero or not
            for(int i = 1; i < n; i++){
                if(matrix[i][0] == 0){

                    firstCol = true;
                    break;
                }
            }
        }

        // for the rest of the elements
                
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){

                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){

                if(matrix[0][j] == 0 || matrix[i][0] == 0){                    
                    matrix[i][j] = 0;
                }
            }
        }

        if(TopLeftCell == true){

            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;                             
            }
            
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }   
        }

        if(firstRow){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;                             
            }
        }

        if(firstCol){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }   
        }
        
    }
};