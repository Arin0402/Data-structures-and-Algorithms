#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/clone-graph/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 1
// BFS
// TC = O(V + 2E)

class Solution {
public:    

    Node* cloneGraph(Node* node) {

        if(!node) return NULL;

        // original , clone
        unordered_map<Node*, Node*> mp; 
      
        queue<Node*> q;
        q.push(node);

        // just to return the starting of the cloned graph
        int startingNodeVal = node->val;        
        Node* HeadOfTheClonedGraph;

        while(!q.empty()){
            
            Node* curr = q.front();
            q.pop();

            // the current node is not present in the map so make a clone of it
            if(mp.find(curr) == mp.end()){
                Node* newNode = new Node(curr->val);
                mp[curr] = newNode;                
            }

            // simple logic to check if it is the starting node
            if(curr->val == startingNodeVal){
                HeadOfTheClonedGraph = mp[curr];
            }

            for(Node* neigh : curr->neighbors){
           
                // neighbor is also not present so create it
                // NOTE: we will insert only those nighbors into queue which are not cloned yet                
                if(mp.find(neigh) == mp.end()){
                    Node* newNode = new Node(neigh->val);
                    mp[neigh] = newNode;
                    q.push(neigh);
                }

                // inserting the cloned neighbor
                mp[curr]->neighbors.push_back(mp[neigh]);                                           
            }
        }

        return HeadOfTheClonedGraph;
    }
};

// 2
// DFS
// TC = O(V + 2E)

class Solution {
    public:
    
    Node* dfs(Node* curr, unordered_map<Node*, Node*> &mp){
        
        Node* clone = new Node(curr->val);
        vector<Node*> neighbor;
        
        mp[curr] = clone;
        
        for(auto ele : curr->neighbors){
            
            if(mp.find(ele) != mp.end()){ // clone already present.
                
                neighbor.push_back(mp[ele]);
            }
            else{ // else create clone
                
                neighbor.push_back(dfs(ele, mp));
            }
        }
        
        clone->neighbors = neighbor;
        return clone;
        
    }
    
    Node* cloneGraph(Node* node) {
       
        unordered_map<Node*, Node*> mp;
        
        if(node == NULL) return NULL;
        
        if(node->neighbors.size() == 0){
            
            Node* clone = new Node(node->val);
            return clone;
            
        }
        
        return dfs(node,mp);               
    }
};