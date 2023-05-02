#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// O(nlogn)
// O(n)

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    
    // We traverse both trees simultaneously level by level.
    // We store each level both trees in vectors (or array).
    // To check if two vectors are anagram or not, we sort both and then compare.
    
    
    // function to check if both the levels of trees are same or not.
    bool compare(queue<Node*> &q1, queue<Node*> &q2){
        
        vector<int> first, second;
        
        int n1 = q1.size();
        
        for(int i = 0; i < n1; i++){
            Node* temp1 = q1.front();
            int ele1 = temp1->data;
            
            first.push_back(ele1);
            q1.pop();
            q1.push(temp1);
            
            Node* temp2 = q2.front();
            int ele2 = temp2->data;
            
            second.push_back(ele2);
            q2.pop();
            q2.push(temp2);
        }
        
        
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        
        for(int i = 0; i < n1; i++){
            if(first[i] != second[i]) return false;
        }
        
        return true;
        
    }
    
    bool areAnagrams(Node *root1, Node *root2)
    {
        
        queue<Node*> q1, q2;
        
        q1.push(root1);
        q2.push(root2);
        
        // level order traversal
        while(!q1.empty() && !q2.empty()){
            
            int n1 = q1.size();
            int n2 = q2.size();
            
            // size different.
            if(n1 != n2) return false;
            if(compare(q1, q2) == false) return false;
            
            // insert the next level into queues.
            for(int i = 0; i < n1; i++){
                
                Node* temp1 = q1.front();
                Node* temp2 = q2.front();
                q1.pop();
                q2.pop();
                
                if(temp1->left) q1.push(temp1->left);
                if(temp1->right) q1.push(temp1->right);
                
                if(temp2->left) q2.push(temp2->left);
                if(temp2->right) q2.push(temp2->right);
            }
            
        }
        
        // if any one is not zero then they are not equal.
        if(q1.size() > 0 || q2.size() > 0) return false;
        return true;
    }
};

// 2
// O(n)
// O(n)
// use of unordered map to compare each level instead of sorting.