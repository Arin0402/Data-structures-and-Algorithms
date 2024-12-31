#include <bits/stdc++.h>
using namespace std;


class Solution
{   
    // This algo is used to count the number of connected components in a graph.
    // NO topological sort is used. JUST the idea is used i.e to insert that node whose dfs is completed
    // into the stack.
    // Can refer Love Babbar's video.    
	public:
	
	// Find the order of elements .
	void dfs(int node, vector<bool> &vis, stack<int> &order, vector<int> adj[] ){
	    
	    vis[node] = true;
	    
	    for(auto ele : adj[node]){ 
	        
	        if(vis[ele] == false){
	            dfs(ele, vis, order, adj);
	        }
	    }
	    
	    order.push(node);
	    
	}
	
	// Traversal after transpose of graph.
	void dfsRev(int node, vector<bool> &vis, vector<int> adj[] ){
	    
	    vis[node] = true;
	    
	    for(auto ele : adj[node]){
	        
	        if(vis[ele] == false){
	            dfsRev(ele, vis, adj);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        stack<int> order;
        
        for(int i = 0; i < V; i++){
            
            if(vis[i] == false){
                dfs(i, vis, order, adj);
            }
        }
        
        
        // Reverse the edges.
        vector<int> transpose[V];
        
        for(int i = 0 ; i< V; i++){
            
            for(auto ele : adj[i]){
                
                transpose[ele].push_back(i);
            }
        }
        
        // Reuse visited vector.
        for(int i = 0; i < V; i++){
            
            vis[i] =false;
        }
        
        
        // count components.
        int cnt = 0;
        
        while(!order.empty()){
            
            int node = order.top();
            order.pop();
            
            if( vis[node] == false){
                
                dfsRev(node, vis, transpose);
                cnt++;
            }
        }
        
        
        return cnt;
        
        
    }
};