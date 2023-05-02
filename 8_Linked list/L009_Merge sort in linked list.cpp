#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};

class Solution{
  public:
    
    Node* middle(Node* head){
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* merge(Node* first, Node* second){
        
        Node* answer = NULL;
        
        if(!first) return second;
        if(!second) return first;
        
        
        if(first->data <= second->data){
            answer = first;
            answer->next = merge(first->next, second);
        }
        else{
            answer = second;
            answer->next = merge(first, second->next);
        }
        
        return answer;
        
    }
    
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = middle(head);
        
        Node* first = head;
        Node* second = mid->next;
        
        mid->next = NULL;
        
        first = mergeSort(first);
        second = mergeSort(second);
        
        head = merge(first, second);
        
        return head;
    }
};
