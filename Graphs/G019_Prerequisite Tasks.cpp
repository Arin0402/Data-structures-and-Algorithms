#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1.
// https://www.youtube.com/watch?v=WAOfKpxYHR8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=24
class Solution{
    public:

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	   
	    // create adjacency list. 
	    vector<int> adj[N];
	    
	    for(auto it : prerequisites){
	        
	        adj[it.second].push_back(it.first); // second task should be performed before first.
	        
	    }
	    
        // if cycle is present , then all the tasks can not be performed.
	    // Detect cycle using BFS. (Kahn's algorithm)
	    int indeg[N] = {0};
        
        for(int i =0 ; i < N; i++){
            
            for(auto ele : adj[i]){
                indeg[ele]++;
            }
        }
        
        queue<int> q;
        
        for(int i =0 ; i< N; i++){
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
        
        if(cnt == N) return true;
        return false;
	    
	}    

};