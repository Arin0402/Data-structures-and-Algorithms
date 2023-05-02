#include <bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         
        if(!head || !head->next) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next ;
        
        int test = 0;
        ListNode* testnode = head;
        
        // to check if group if contains sufficient elements
        while(test < k && testnode ){
            testnode = testnode->next;
            test++;
        }
        
        // if no sufficient elements then no reversing of that group
        if(test < k) return head;
        
        int i = 0;
        while( i< k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        
        
        head->next = reverseKGroup(curr,k);
        
        return prev;
    }
};