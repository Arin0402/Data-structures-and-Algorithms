#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/51afa710a708c0681748445b509696dd588d5c40/1

// 1
// using the concept of cycel detection algorithm in directed graph using DFS (G014)

class Solution
{
  public:
  
    void dfs(int node , vector<bool> &vis,vector<bool> &pathVis, vector<int> adj[], long long &ans){
        
        vis[node] = true; // mark it visited. 
        pathVis[node] = true; // mark it path visited.
        
        for(auto ele : adj[node]){
            
            if(vis[ele] == false) { // visiting first time.
                
                dfs(ele, vis, pathVis, adj, ans);
            }
            // node is visited and on the same path.
            else if(pathVis[ele] == true){
                
                int curr = ele;
                long long val = 0;
                
                do{
                    val += curr;
                    curr = adj[curr][0];
                    
                } while(curr != ele);
                
                ans = max(ans, val);
                
            }
            
            // else 
            // node is visited but on the different path. so no need to visit after this node as 
            // we will not find any cycle further.
        }
        
        pathVis[node] = false; // mark path visited as false on return journey.
    }
    
    long long largestSumCycle(int N, vector<int> Edge)
    {
        vector<int> adj[N];
        
        for(int i = 0; i < N; i++){
            if(Edge[i] != -1)  adj[i].push_back(Edge[i]);
        }
        
        vector<bool> vis(N, false); // mark if the node is visited.
        vector<bool> pathVis(N, false); // mark if the node is visited on the same path.
        
        long long ans = INT_MIN;
        
        for(int i =0 ; i < N ; i++){
            
            if(vis[i] == false){
                dfs( i, vis, pathVis, adj, ans);
            }
        }
        
        
        if(ans == INT_MIN) return -1;
        return ans;
        
    }
};