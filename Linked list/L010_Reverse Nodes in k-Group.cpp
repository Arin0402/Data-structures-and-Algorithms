#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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

        // temporary count.
        int t = 0;

        // temporary pointer
        ListNode* test = head;
        
        // move the pointer and increase the counter
        for(int i = 0; i < k; i++){            
            if(test) test = test->next;
            else break;           

            t++;
        }

        // k nodes are not available
        if(t < k) return head;

        // reverse function
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        for(int i = 0; i < k; i++){            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // go for the next set.
        head->next = reverseKGroup(curr, k);

        return prev;

    }
};