#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        
    // first we reverse all the edges of the graph.
    // then apply BFS topo sort to find elements which are not in any cycle and not connected to any cycle.
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> adjRev[V]; // reverse the edges.
        
        // rest is same as kahn's algorithm.
        
        int indeg[V] = {0}; // indegrees
        
        for(int i =0 ; i < V; i++ ){
            
            for(auto ele : adj[i]){
                adjRev[ele].push_back(i);
                indeg[i]++;
            }
        }
        
        
        queue<int> q;
        
        for(int i =0 ; i < V; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        vector<int> topo;    
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            
            topo.push_back(node);
            
            for(auto ele : adjRev[node]){
                
                indeg[ele]--;
                
                if(indeg[ele] == 0) q.push(ele);
            }
            
        }
        
        sort(topo.begin(), topo.end());
        
        return topo;
    }
};