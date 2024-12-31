#include <bits/stdc++.h>
using namespace std;

//https://leetcode. com/problems/clone-graph/


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