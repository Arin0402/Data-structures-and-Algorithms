#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Using Kahn's algorithm.
    // if number of elements in topo sort is not equal to the total number of elements , then cycle is present.
    bool isCyclic(int V, vector<int> adj[]) {
        
        
        int indeg[V] = {0};
        
        for(int i =0 ; i < V; i++){
            
            for(auto ele : adj[i]){
                indeg[ele]++;
            }
        }
        
        queue<int> q;
        
        for(int i =0 ; i< V; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            cnt++; // count the number of nodes.
            
            for(auto ele : adj[node]){
                
                indeg[ele]--;
                
                if(indeg[ele] == 0) q.push(ele);
            }
        }
        
        if(cnt == V) return false;
        return true;
    
    }
};