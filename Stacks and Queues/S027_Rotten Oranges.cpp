#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

// 1
// O(R*C)
struct Pair{
    int row;
    int col;
};

class Solution 
{
    public:
    
    int helper( queue<Pair*> &q,vector<vector<int>>& grid, int n, int m, int &fresh){
        
        if(q.empty()) return 0;
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
        
        time = 1 + helper(q, grid, n, m, fresh);
        
        return time;
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<Pair*> q;
        
        int fresh = 0;
        
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
        
        if(q.empty()) return 0;
        int time = helper(q, grid, n, m, fresh);
        
        if(fresh != 0) return -1;
        return time;
    }
};