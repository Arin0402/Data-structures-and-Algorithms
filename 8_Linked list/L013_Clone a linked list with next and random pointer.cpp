#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://www.youtube.com/watch?v=VNf6VynfpdM

struct Node{
	int data;
	struct Node * next;
	struct Node * arb;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    arb = NULL;
	}
	
};

// 1
// using map
// store the original and the copy node in the map in a pair
// then acoordingly assign pointers

// 2
// optimised without any extra space
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        if(!head) return NULL;
        Node* l1 = head;
        
        // inserting copy nodes in original list 
        while(l1){
            Node* new_node = new Node( l1->data);                                        
            new_node->next = l1->next;
            l1->next = new_node;
            l1 = l1->next->next;            
        }
        
        l1 = head;
        Node* l2 = l1->next;
        
        // assigniing arb pointers to copy nodes
        while(l1){
            if(l1->arb){
                l2->arb = l1->arb->next;
            }
            l1 = l1->next->next;
            if(l2->next) l2 = l2->next->next;
        }
        
        l1 = head;
        l2 = l1->next;
        Node* final_list = l1->next;
        
        // Seperating both the linked lists        
        while(l1){
            l1->next = l1->next->next;
            l1 = l1->next;
            if(l2->next) l2->next = l2->next->next;
            l2 = l2->next;            
        }
        
            
            
        return final_list ;

    }

};
