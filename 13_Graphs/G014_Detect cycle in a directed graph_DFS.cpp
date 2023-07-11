#include <bits/stdc++.h>
using namespace std;

// Using two vectors.
// This is better solution as it has code readability.
class Solution1 {
    public:

        // TC - O(V + E)
        bool dfs(int node , vector<bool> &vis,vector<bool> &pathVis, vector<int> adj[] ){
        
        vis[node] = true; // mark it visited. 
        pathVis[node] = true; // mark it path visited.
        
        for(auto ele : adj[node]){
            
            if(vis[ele] == false) { // visiting first time.
                
                if(dfs(ele, vis, pathVis, adj) == true) return true;
            }
            // node is visited and on the same path.
            else if(pathVis[ele] == true) return true;
            
            // else 
            // node is visited but on the different path. so no need to visit after this node as 
            // we will not find any cycle further.
        }
        
        
        pathVis[node] = false; // mark path visited as false on return journey.
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false); // mark if the node is visited.
        vector<bool> pathVis(V, false); // mark if the node is visited on the same path.
        
        for(int i =0 ; i< V ; i++){
            
            if(vis[i] == false){
                if(dfs(i, vis, pathVis, adj) == true) return true;
            }
        }
        
        return false;
        
        
    }
};


// using siingle vector
// Bad code quality and code readibility.
class Solution2{

    public:

        // Note :- 2 means visited andd path visited both, 1 means only visited but not path visited
        bool dfs(int node , vector<int> &vis, vector<int> adj[] ){
        
            vis[node] = 2; // mark it visited ands path visited. 
            
            for(auto ele : adj[node]){
                
                if(vis[ele] == -1) { // visiting first time.
                    
                    if(dfs(ele, vis, adj) == true) return true;
                }
                // node is visited and on the same path.
                else if(vis[ele] == 2) return true;
                
                // else 
                // node is visited but on the different path. so no need to visit after this node as 
                // we will not find any cycle further.
            }
            
            
            vis[node] = 1; // mark path visited as false on return journey.
            
            return false;
        }
        
        bool isCyclic(int V, vector<int> adj[]) {
            
            vector<int> vis(V, -1); // mark if the node is visited.
            
            for(int i =0 ; i< V ; i++){
                
                if(vis[i] == -1){
                    if(dfs(i, vis,  adj) == true) return true;
                }
            }
            
            return false;
            
            
        }
};