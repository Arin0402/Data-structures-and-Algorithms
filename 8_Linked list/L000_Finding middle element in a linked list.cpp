#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        
        Node* slow = head;
        Node* fast = head;
        
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
};
