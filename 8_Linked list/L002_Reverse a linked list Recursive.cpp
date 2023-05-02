#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
    public:
    //Function to reverse a linked list.
    
    Node* helper(Node* head){
        
        if(!head || !head->next){
            return head;
        }
        
        Node* rest = helper(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return rest;
        
    }
    
    struct Node* reverseList(struct Node *head)
    {   
        return helper(head);
    }
    
};
    
