#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// 1
// using map
// store the values and check if it has again occured

// 2
// two pointer approach
// why does this work ? 
// https://youtu.be/354J83hX7RI?t=385

struct Node
{
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
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(slow && fast){
            
            slow = slow->next;
            
            if(fast->next) fast = fast->next->next;
            else fast = fast->next;
            
            if(slow == fast && slow != NULL && fast != NULL) return true;
            
        }
        
        return false;
    }
};
