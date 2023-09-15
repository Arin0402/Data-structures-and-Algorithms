#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution{

    public:
    // same code as detect cycle in directed graph.
    // just find those nodes which are not in any cycle and are not connected to any cycle.
    
    bool dfs(int node, vector<int> &vis,vector<int> &pathVis, vector<int> adj[] ){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto ele : adj[node]){
            
            if(vis[ele] == -1){
                if(dfs(ele, vis, pathVis, adj) == true) return true;
            }
            else if(pathVis[ele] == 1 ) return true;
            
        }
        
        pathVis[node] = 0;
        
        return false;
        
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> vis(V, -1);
        vector<int> pathVis(V, -1);
        
        vector<int> ans;
        
        for(int i =0 ; i < V; i++){
            
            if(vis[i] == -1) dfs(i, vis, pathVis, adj); // check for all the nodes.
            
        }
        
        // if a node is in a cycle or a node is connected to a cycle then it will have its path visited as 1.
        for(int i =0 ; i < V; i++ ){
            if(pathVis[i] == 0) ans.push_back(i);
        }
    
        return ans;
        
    }
};