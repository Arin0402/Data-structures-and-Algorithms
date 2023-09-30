#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ipair;

class Solution
{
	public:	
	// TC - O(V + E) + LogV
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    
        vector<int> key(V, INT_MAX); // store the weights
        vector<bool> inMst(V, false); // if the node is in mst or not.
        vector<int> parent(V, -1); // denotes the parent of each node.
        
        key[0] = 0; // mark weight of source is zero.
        parent[0] = -1;
        
        // will give the edge with minimum weight.
        priority_queue<ipair, vector<ipair>, greater<ipair>> pq; // logV
        pq.push({0,0}); //{weight, index}
        
        // O(V + E)
        while(!pq.empty()){
            
            int node = pq.top().second; // node with minimum weight.
            pq.pop();
            
            inMst[node] = true; // insert into mst.
            
            for(auto p :  adj[node]){
                
                int ele = p[0];
                int weight = p[1];
                
                if(inMst[ele] == false && weight < key[ele]){ // node is not in mst and weight of edge is less than its value in key vector.
                    key[ele] = weight;
                    parent[ele] = node;
                    pq.push({key[ele], ele});
                }
                
            }
            
        }
        
        int sum = 0;
        
        for(int i =0 ; i < V; i++) sum += key[i];
        
        return sum;
        
    }
};