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
        
        vector<int> ans(N, INT_MAX);
        queue<int> q;
        
        ans[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto ele : adj[node]){
                
                if( ans[node] + 1  < ans[ele]) {
                    ans[ele] = ans[node] + 1;
                    q.push(ele);
                }
            }
        }
        
        for (int i = 0; i < N; i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }
        
        return ans;
    }
};
