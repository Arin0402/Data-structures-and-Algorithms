#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Try every path from the source node.
    // Finding the longest path from the sorce node to all the nodes won't work (as done in question G040)
    // as it is undirected graph. (try using two nodes)
    // So we will travel along the vertices and add up the weights.
    // if got the answer then return otherwise try another path.
    bool dfs(int node,int totalWeight, vector<bool> &vis, vector<pair<int, int>> adj[], int k){
      
        if(totalWeight >= k) return true;
        vis[node] = true;
        
        for(auto row : adj[node] ){
            
            int ele = row.first;
            int weight = row.second;
            
            if(vis[ele] == false){
                
                if(dfs(ele, totalWeight + weight, vis, adj, k) == true) return true ;
            }
            
        }
        
        vis[node] = false;
        return false;
        
    }
    
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
        
       // creating adjacency list.
       vector<pair<int, int>> adj[V];
     
       for(int i =0 ; i < E*3; i += 3){
           
           int first = a[i];
           int second = a[i+1];
           int weight = a[i+2];
           
           adj[first].push_back({second, weight});
           adj[second].push_back({first, weight});
       }
       
       vector<bool> vis(V, false);
       
       return dfs(0, 0, vis, adj, k);
       
       
    } 
};

