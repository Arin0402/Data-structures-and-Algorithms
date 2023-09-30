#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// 1
// using extra space.
// TC - 3^(N^2) , for every cell at most three calls will be made.
// SC - 3^(N^2) , due to visited matrix.

class Solution
{
public:
    bool check(int row, int col, vector<vector<int>> &m, int n, vector<vector<bool>> &visited)
    {

        if (row >= n || col >= n)
            return false;
        if (row < 0 || col < 0)
            return false;

        if (m[row][col] == 1 && visited[row][col] == false)
            return true;

        return false;
    }

    void possiblePaths(int row, int col, string s, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<bool>> &visited)
    {

        // base case
        if (row == n - 1 && col == n - 1)
        {

            ans.push_back(s);            
            return;
        }

        visited[row][col] = true;

        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, -1, 0, 1};
        char direc[4] = {'U', 'L', 'D', 'R'};

        for (int i = 0; i < 4; i++)
        {

            int nrow = rows[i] + row;
            int ncol = cols[i] + col;

            if (check(nrow, ncol, m, n, visited))
            {                
                s.push_back(direc[i]);
                possiblePaths(nrow, ncol, s, m, n, ans, visited);
                s.pop_back();                
            }
        }

        visited[row][col] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {

        vector<string> ans;

        if (m[0][0] == 0)
            return ans; // can not go if starting position is zero.
        if (m[n - 1][n - 1] == 0)
            return ans; // can not go if ending position is zero.

        vector<vector<bool>> visited(n, vector<bool>(n, false));        

        string s = "";

        possiblePaths(0, 0, s, m, n, ans, visited);

        return ans;
    }
};

// 2
// without extra space
// modify the given matrix.
// mark visited by 2.

class Solution{
    public:
    
    bool check(int row, int col, int n, vector<vector<int>> &m){
        
        if(row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1) return true;
        return false;
        
    }
    
    void helper(int row, int  col, string temp, vector<vector<int>> &m, vector<string> &ans, int n ){
        
        if(row == n-1 && col == n-1){
            ans.push_back(temp);
            return;
        }
        
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};
        char direc[4] = {'U', 'R', 'D', 'L'};
        
        for(int i =0 ; i < 4; i++){
            
            int nrow = row + rows[i];
            int ncol = col + cols[i];
            
            if(check(nrow, ncol, n, m)){
                
                temp.push_back(direc[i]);
                m[nrow][ncol] = 2;
                
                helper(nrow, ncol, temp, m, ans, n);
                
                temp.pop_back();
                m[nrow][ncol] = 1;
                
            }
            
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        
        if(m[0][0] == 0) return ans;
        if(m[n-1][n-1] == 0) return ans;
        
        m[0][0] = 2;
        
        helper(0, 0,"", m, ans, n);
        
        return ans;
        
    }
};

    
