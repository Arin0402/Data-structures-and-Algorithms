#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:    
    
    bool check(int r, int c , int N ){
        
        if(r >= 0 && r < N && c >= 0 && c < N ) return true;
        
        return false;
    }
    
    
    int bfs(int rk, int ck, int rt, int ct ,  vector<vector<int>> &step ,int N){
        
        int ans = INT_MAX; 
        
        step[rk][ck] = 0; // mark the steps at the knight's position as zero;
        
        queue<pair<pair<int,int>, int >> q; // store the coordinates and steps.
        
        q.push({{rk, ck}, 0}); // push knight's position initially.
        
        
        int rows[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int cols[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            
            int steps = q.front().second;
            
            q.pop();
            
            if(r == rt && c == ct) ans = min(ans, steps); // reached the final target.
            
            for(int i =0 ; i< 8; i++){
            
                int nrow = r + rows[i];
                int ncol = c + cols[i];
                
                // can go.
                if(check(nrow, ncol, N)){
                    
                    if( steps + 1 < step[nrow][ncol]){ // if we can reach the new position in less number of steps.
                        
                        step[nrow][ncol] = steps + 1 ; // update the steps at the new position.
                        q.push({{nrow, ncol }, step[nrow][ncol] });
                        
                    }
                    
                }
                
            }
            
        }
        
        return ans;
        
        
    }
    
	int minStepToReachTarget(vector<int> &KnightPos , vector<int> &TargetPos, int N)
	{
	    // visited matrix;
	    vector<vector<int>> step(N , vector<int>(N, INT_MAX));
	    
	    // knight coordinates
	    int rk = KnightPos[0] - 1;
	    int ck = KnightPos[1] - 1;
	    
	    // target cordinates
	    int rt = TargetPos[0] - 1;
	    int ct = TargetPos[1] - 1;
	    
	    return bfs(rk , ck ,rt, ct,step,N );
	    
	}
};