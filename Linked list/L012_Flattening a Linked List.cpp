#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=41

// 1
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// simple merge two linked lists
Node* merge(Node* first, Node* second){
        
    Node* head3 = new Node(-1);
    Node* third = head3;
    
    while(first && second){
        
        if(first->data < second->data){
            third->bottom = first;
            third = first;
            first = first->bottom;
        }
        else{
            third->bottom = second;
            third = second;
            second = second->bottom;
        }
    }
    
    if(first){
        third->bottom = first;
    }
    else {
        third->bottom = second;
    }
    
    return head3->bottom;
}

Node *flatten(Node *head)
{
    
    if(!head || !head->next) return head;
    
    // go to the last node first.
    // then come to the front by solving from the last.
    head->next = flatten(head->next);
    head = merge(head, head->next);
    
    
    return head;
       
}
