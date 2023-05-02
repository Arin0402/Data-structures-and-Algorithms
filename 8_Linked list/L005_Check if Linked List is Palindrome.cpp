#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// 1
// optimised approeach 
// 1. find the mid 
// 2. reverse the second half
// 3. check for equality

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* middle(Node* head){
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next){
            
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
        }
        
        return slow;
        
    }
    Node* reverse(Node* head){
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    bool isPalindrome(Node *head)
    {
        Node* mid = middle(head);
        mid->next = reverse(mid->next);
        
        Node* t1 = head;
        Node* t2 = mid->next;
        
        while(t1 && t2){
            if(t1->data != t2->data) return false;
            
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
        
    }
};

