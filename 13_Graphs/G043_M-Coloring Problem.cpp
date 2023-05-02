#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    // Try every color for every node.
    bool isPossible(int node,int color, vector<int> adj[] ,vector<int> colors ){
        
        for(auto ele : adj[node]){
            
            if(colors[ele] == color) return false;
        }
        
        return true;
        
    }
    
    bool solve(int node, vector<int> adj[] ,vector<int> colors, int n, int m ){
        
        if(node >= n) return true;
        
        for(int i =0; i < m; i++){
            
            if(isPossible(node, i, adj, colors)){
                
                colors[node] = i;
                if(solve(node + 1,  adj, colors, n, m  )) return true;
                colors[node] = -1;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        // creating adjacnency list.
        vector<int> adj[n];
        
        for(int i =0 ; i < n; i++){
            
            for(int j = 0; j < n; j++){
                
                if(graph[i][j] == 1){
                    
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> colors(n, -1);
        return solve(0, adj, colors, n, m );
        
    }
};