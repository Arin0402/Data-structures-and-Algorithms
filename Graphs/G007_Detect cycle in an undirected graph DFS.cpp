#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// TC - O (N + 2*E) + O(N).

class Solution {
    public:
    bool dfs(int src, int parent, vector<int> adj[], vector<bool> &vis){
        
        vis[src] = true;
        
        for(auto ele : adj[src]){
            
            if(vis[ele] == false){
                
                if(dfs(ele, src, adj, vis)) return true;
            }
            else if(ele != parent) return true; // ele is not equal to the parent value of the current node.
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        
        vector<bool> vis(V, false);
        vector<int> parentArr(V, -1);
        
        for(int i = 0 ; i < V ; i++){
            
            if(vis[i] == false){
                if(dfs(i, -1,adj, vis)) return true;
            }
        }
        
        return false;
        
        
    }

};
