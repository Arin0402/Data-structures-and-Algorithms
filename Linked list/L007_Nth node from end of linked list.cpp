#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// 1
// count the total number of nodes and then find the answer.

// 2
// using two pointers

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{   
    
    Node* slow = head;
    Node* fast = head;
    
    for(int i = 0; i < n; i++){
        
        if(fast)
            fast = fast->next;
        else return -1;
        
    }
            
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->data;
}

 