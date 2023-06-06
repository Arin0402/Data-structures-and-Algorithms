#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution {
public:
    
    // for each subtree we will return the time required to take all the appels in that subtree and the no. of apples in that subtree

    // <time, apples>
    pair<int, int> helper(int root, vector<int> adj[], vector<bool>& hasApple, vector<bool> &visited){
        
        // leaf node        
        if(adj[root].size() == 0){

            // this node constains apples
            if(hasApple[root]) return make_pair(0, 1);

            // no apple
            return make_pair(0, 0);
        } 

        // total time required for this subtree
        int time = 0;
        // total no. of apples in this subtree
        int apples = 0;

        for(int i = 0; i < adj[root].size(); i++){
            
            // child of the tree
            // NOTE- child can contain the parent also
            // that is why we are taking visited array
            int child = adj[root][i];

            // unvisited
            if(visited[child] == false){
                
                // mark visited
                visited[child] = true;

                pair<int, int> temp = helper(child, adj, hasApple, visited);

                // mark unvisited
                visited[child] = false;
            
                // this part has apples 
                if(temp.second > 0){

                    // +2 is done because it will be the time required to go to the child node
                    // and coming back
                    time += temp.first + 2;
                    apples += temp.second;
                }
            }            
        }

        // check if the current node is apple
        if( hasApple[root]) apples++;

        return make_pair(time, apples);                
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        // adjacency list
        vector<int> adj[n];

        // visited array
        vector<bool> visited(n, false);
        visited[0] = true;

        for(auto vec : edges){
            adj[vec[0]].push_back(vec[1]);        
            adj[vec[1]].push_back(vec[0]);        
        }

        pair<int, int> ans = helper(0, adj, hasApple, visited);

        return ans.first;
    }
};