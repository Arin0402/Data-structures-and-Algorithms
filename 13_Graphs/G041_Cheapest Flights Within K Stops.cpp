#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

// Solution 1
// Intution based on BFS.
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
         // create adjacency list.
        vector<pair<int , int>> adj[n];
        
        for(auto row : flights){            
            int first = row[0];
            int sec = row[1];
            int price = row[2];            
            adj[first].push_back({sec, price});
        }

        // No need to use Priority queue as the stops are increasing linearly
        // and it may happen that the shortest distance will run out of stops limit
        // and longer distance will give answer in stops limit.

        queue<pair<int, pair<int, int>>> q; // {src, {price, stops} }
        q.push({src, {0, 0} });
        
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
                
                        
        while(!q.empty()){
            
            int node = q.front().first;            
            int price_node = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
                        
            for(auto row : adj[node]){
                                
                int ele = row.first;
                int price = row.second;                                
                                    
                if( price_node + price < prices[ele] &&  stops <= k ){
                    
                    prices[ele] =  price_node + price;
                    int totalPrice = price_node + price;                    
                    
                    // if destination is reached, then there is no point in finding distance for its adjacent nodes. So don't push.                                                                        
                    if(ele != dst) 
                        q.push({ele, {totalPrice, stops + 1}});                    
                                        
                }                
            }
            
        }
                        
        if(prices[dst] != INT_MAX) return prices[dst];
        return -1;
    
    }
};

// Solution 2
// using Bellman ford algo
// Neetcode video.
int BFA(int n, vector<vector<int>>& flights, int src, int dst, int k){
    
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    for(int i =0 ; i <= k; i++){
        
        vector<int> temp(dist);
        
        for(auto row : flights){
            
            int first = row[0];
            int second = row[1];
            int weight = row[2];
            
            if(dist[first] != INT_MAX){
                temp[second] = min(temp[second], dist[first] + weight);
            }
        }
        
        dist = temp;
    }
    
    if(dist[dst] != INT_MAX) return dist[dst];
    return -1;
}