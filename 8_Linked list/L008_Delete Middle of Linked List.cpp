#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

// same as finding the middle element of linked list.
// just keep the previous pointer

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;
    
    while( fast && fast->next){
        
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
            
    }
    
    if(prev == NULL) return NULL;
    
    prev->next = slow->next;
    
    return head;
}