// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
#include <bits/stdc++.h>
using namespace std;

// O(n*m) + O(n*m)*4 = O(N^2).
class Solution
{
public:
    void Helper(int r, int c, vector<vector<int>>& image, int newColor, int startingColor, 
                int rowLength, int colLength ){
        
        
        int rows[4] = {-1,0,1,0};
        int cols[4] = {0,1,0,-1};
        
        for(int i =0 ; i < 4; i++){
            
            int nrow = r + rows[i];
            int ncol = c + cols[i];
            
            if( nrow >= 0 && nrow < rowLength && ncol >= 0 && ncol < colLength && image[nrow][ncol] == startingColor ){
                
                image[nrow][ncol] = newColor;
                Helper(nrow , ncol , image , newColor, startingColor, rowLength, colLength);    
            }
            
            
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int rowLength = image.size();
        int colLength = image[0].size();
        
        int startingColor = image[sr][sc];
        
        if(startingColor == newColor) return image;
        
        image[sr][sc] = newColor;
        
        Helper(sr, sc, image, newColor, startingColor, rowLength, colLength );
        
        return image;
                            
    }
    
};