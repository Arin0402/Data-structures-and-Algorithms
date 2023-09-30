#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination
// https://www.youtube.com/watch?v=_-0mx0SmYxA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=40
typedef pair<int, int> ip;
class Solution {
  public:
  
    // Using Dijkastra's algo.
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // adjacency list.
        vector<ip> adj[n];
        
        for(auto row : roads){
            
            int first = row[0];
            int sec = row[1];
            int weight = row[2];
            
            adj[first].push_back({sec, weight});
            adj[sec].push_back({first, weight});
        }
        
        
        // priority queue
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        pq.push({0, 0}); //{dist, node}
        
        vector<int> dist(n, 1e9), ways(n , 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto p : adj[node]){
                
                int ele = p.first;
                int weight  = p.second;
                
                // reaching the node first time.
                // so number of ways would be same as that of node.
                if(dis + weight < dist[ele]){
                    dist[ele] = dis + weight;
                    ways[ele] = ways[node];
                    pq.push({dist[ele], ele });
                    
                }
                
                // already reached the node before with the same distance
                // so the ways will be added with number of ways of node.
                else if(dis + weight  == dist[ele]){
                    
                    ways[ele] += ways[node]%(1000000007);
                }
            }
        }
        
        return ways[n-1]%(1000000007);
                            
        
    }
};