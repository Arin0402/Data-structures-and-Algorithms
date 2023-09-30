#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

class Solution
{
    public:
    
    // Do a bfs and traverse to all the adjacent nodes starting from the source node.
    // update the distance if it is greater.
    vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
    {
        
        // create adjacency list.
        vector<pair<int, int>> adj[v];
        
        for(auto vec : edges){
            
            int first = vec[0];
            int second = vec[1];
            int weight = vec[2];
            
            adj[first].push_back({second, weight});
            
        }
        
        vector<int> dis(v, INT_MIN); // distance vector
        dis[src] = 0; // distance of source is zero.
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto p : adj[node]){
                
               int ele = p.first;
               int weight  = p.second;
               
               if(dis[node] + weight > dis[ele]){ // update the distance.
                   dis[ele] = dis[node] + weight;
                   q.push(ele);
               }
                
            }
            
        }
        
        return dis;
    }
};