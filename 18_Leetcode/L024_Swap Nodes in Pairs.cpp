#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        ListNode *back = NULL; // after swapping prev and curr node, this will help to connect the preceding part of the linked list to the newly swapped linked list.

        ListNode *prev = head;       // first node.
        ListNode *curr = head->next; // second node.
        ListNode *start = curr;      // to be returned at last.

        while (prev && curr)
        {

            if (back)
                back->next = curr; // when swapping first two nodes. (there is no preceding part of linked list)

            // swapping.
            prev->next = curr->next;
            curr->next = prev;

            // connect the preceding part.
            back = prev;

            // move the pointers.
            prev = prev->next;
            if (prev)
                curr = prev->next;
        }

        return start;
    }
};