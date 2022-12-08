#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool check(int row ,int col ,vector<vector<int>> &m, int n , vector<vector<bool>> &visited ){
        
        if(row >= n  || col >= n ) return false;
        if(row < 0  || col < 0 ) return false;
        
        
        if(m[row][col] == 1 && visited[row][col] == false ) return true;
        
        
        return false;
    }
    
    void possiblePaths(int row , int col, string s, vector<vector<int>> &m, int n, vector<string>& ans, vector<vector<bool>> &visited  ){
        
        //base case
        if( row == n-1 && col == n-1 ){
            
            ans.push_back(s);
            visited[row][col] = false;
            return;
        }    
        
        
        if(check(row + 1, col, m, n, visited)){
            
            visited[row + 1][col] = true;
            s.push_back('D');
            possiblePaths(row + 1,col, s, m, n, ans , visited);
            s.pop_back();
            visited[row + 1][col] = false;
            
        }
        if(check(row , col - 1, m, n, visited)){
            
            visited[row ][col - 1] = true;
            s.push_back('L');
            possiblePaths(row ,col- 1 ,  s, m, n, ans , visited);
            s.pop_back();
            visited[row ][col - 1] = false;
        }
            
        if(check(row , col + 1, m, n, visited )){
            
            visited[row][col + 1] = true;
            s.push_back('R');
            possiblePaths(row ,col + 1, s , m, n, ans, visited);
            s.pop_back();
            visited[row][col + 1] = false;
            
        }
        
        
        if(check(row - 1, col, m, n, visited)){
            
            visited[row - 1][col] = true;
            s.push_back('U');
            possiblePaths(row - 1,col, s, m, n, ans , visited);
            s.pop_back();
            visited[row - 1][col] = false;
            
        }
        
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        
        vector<string> ans;
        
        if(m[0][0] == 0) return ans; //can not go if starting position is zero.
        
        vector<vector<bool>> visited(n ,vector<bool>(n ,false) );
        visited[0][0] = true;
        
        string s = "";
        
        possiblePaths(0 ,0, s, m, n, ans, visited);
        
        return ans;
        
    }
};