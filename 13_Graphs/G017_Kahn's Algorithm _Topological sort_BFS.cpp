#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    // calculate indegree of all the nodes.
	    int indegree[V] = {0};
	    
	    for(int i =0 ; i< V; i++){
	        
	        for(auto ele : adj[i]){
	            indegree[ele]++;
	        }
	    }
	    
	    // Push all the nodes with indegree zero.
	    // elements with indegree zero will be the first elements.
	    queue<int> q;
	    
	    for(int i = 0 ; i< V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto ele : adj[node] ){
	            
	            indegree[ele]--; // subtract the indegrees for the adjacent nodes of the current node.
	            
	            if(indegree[ele] == 0) q.push(ele);
	        }
	        
	        
	    }
	    
	    
	    return topo;
	    
	}
};