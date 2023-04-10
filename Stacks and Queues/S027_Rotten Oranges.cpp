#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

// 1
// TC - O(R*C)
// Each element of the matrix can be inserted into the queue only once so the upper bound of iteration is O(R*C), i.e. the number of elements. So time complexity is O(R *C).

// SC - O(R*C). 
// To store the elements in a queue O(R*C) space is needed.
struct Pair{
    int row;
    int col;
};

class Solution 
{
    public:
    
    int helper( queue<Pair*> &q,vector<vector<int>>& grid, int n, int m, int &fresh){
        
        // rot all the oranges, so return
        if(fresh == 0) return 0;
        
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, -1, 0, 1};
        
        int time = 0;
        int size = q.size();
            
        for(int k = 0; k < size; k++){
            
            Pair *p = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                
                int nrow = rows[i] + p->row;
                int ncol = cols[i] + p->col;
                
                // try all the four directions 
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    
                    Pair *temp = new Pair();
                    temp->row = nrow;
                    temp->col = ncol;
                    
                    q.push(temp);
                    fresh--;
                }
            }
                 
        }
        
        // no more rotten oranges
        if(q.empty()) return 0;
        
        time = 1 + helper(q, grid, n, m, fresh);
        
        return time;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<Pair*> q;
        
        int fresh = 0;
        
        // insert all the rotten oranges in the queue
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                
                if(grid[i][j] == 2){
                    
                    Pair *p = new Pair();
                    p->row = i; 
                    p->col = j;
                    q.push(p);
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        // no rotten oranges available
        if(q.empty()) return 0;
        
        // fins the time
        int time = helper(q, grid, n, m, fresh);
        
        // not possinble ot rot all the oranges
        if(fresh != 0) return -1;
        
        // return the required time
        return time;
    }
};