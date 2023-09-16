#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        
        for(auto vec : edges){
            
            int first = vec[0];
            int second = vec[1];
            
            adj[first].push_back(second);
            adj[second].push_back(first);
            
        }
        
        vector<int> ans(N, -1);
        queue<pair<int, int>> q;
        
        ans[src] = 0;
        q.push({src,0});
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            int node = p.first;
            int dist = p.second;
            
            for(auto ele : adj[node]){
                
                if(ans[ele] == -1 || ans[node] + 1  < ans[ele]) {
                    ans[ele] = ans[node] + 1;
                    q.push({ele, ans[ele]});
                }
            }
        }
        
        return ans;
    }
};

