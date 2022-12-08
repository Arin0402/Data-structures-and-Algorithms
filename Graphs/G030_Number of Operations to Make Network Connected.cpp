#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Number of cables required will be number of components - 1.
    
    void bfs(int node, vector<int> &vis, vector<int> adj[] ){
        
        queue<int> q;
        q.push(node);
        
        vis[node] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto ele : adj[node]){
                
                if(vis[ele] == 0){
                    vis[ele] = 1;
                    q.push(ele);
                }
            }                        
            
        }
        
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
            
        int cables = connections.size();
        
        if(cables < n-1) return -1; // if the cables are less than computers then not possible.
        
        // create adj list.
        vector<int> adj[n];
                
        for(int i = 0 ; i < connections.size(); i++){
                            
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
            
        vector<int> vis(n, 0);
        int components =0; // number of components.
        
        for(int i =0 ; i < n; i++ ){
            
            if(vis[i] == 0){
                bfs(i, vis, adj);
                components++;
                
            }
        }
        
        
        return components -1;
            
    }
};