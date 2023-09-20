#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/description/

// 1
// using map

// 2
// two pointers

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL) return NULL;

        do{
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
            else fast = fast->next;
        }while(slow != fast && slow && fast);

        if(slow == NULL || fast == NULL) return NULL;


        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return fast;

    }
};