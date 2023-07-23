#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
    public:
    
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        
        for(int i = 0 ; i < N-1; i++){ 
            
            string s1 = dict[i]; // compre two words at a time.
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size()); // compare each letter of the two words.
            int ptr = 0;
            
            while(ptr < len && s1[ptr] == s2[ptr] ) ptr++; // both the letters are same.
            
            if(ptr < len){ // found a different letter.
                
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // create a edge between the letters.
            }
        }
        
        // apply topo sort (Kahn's algorithm)
        
        int indeg[K] = {0};
        
        for(int i =0  ; i< K; i++){
            
            for(auto ele : adj[i]){
                
                indeg[ele]++;
            }
        }
        
        queue<int> q;
        
        for(int i =0 ;i < K ;i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        string s = "";
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            s += char(node + 'a'); // convert index to letter.
            
            for(auto ele: adj[node]){
                
                indeg[ele]--;
                if(indeg[ele] == 0) q.push(ele);
            }
        }
        
        return s;
        
        
    }
};

// This will not work for the test case such as abc, abcd
// OR if there is a cycle in a graph, ex - abc, bcd, acd