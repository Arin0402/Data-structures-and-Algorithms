#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

// 1
// rotate one by one
// we have to go to the end for each k.
// O(k*n)

// 2
// optimised
// O(n)
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(!head) return head;
        
        
        // put the pointer k steps forward.
        Node* prev;
        Node* temp = head;
        
        for(int i = 0; i < k; i++){
            prev = temp;
            temp = temp->next;
        }
        
        // k == length of the linked list.    
        if(temp == NULL) return head;
        
        // mark the starting
        Node* curr = temp;
        
        // go to the last node
        while(temp->next) temp = temp->next;
        
        // this is the last node now.
        prev->next = NULL;
        
        // connect.
        temp->next = head;
        
        return curr;
        
    }
};
    
