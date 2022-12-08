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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *l1 = list1;
        ListNode *l2 = list2;

        ListNode *Merged_list;

        if (l1->val <= l2->val)
        {
            Merged_list = l1;
            l1 = l1->next;
        }
        else
        {
            Merged_list = l2;
            l2 = l2->next;
        }

        ListNode *l3 = Merged_list;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l3 = l1;
                l1 = l1->next;
            }
            else
            {

                l3->next = l2;
                l3 = l2;
                l2 = l2->next;
            }
        }

        if (!l1)
        {
            while (l2)
            {
                l3->next = l2;
                l3 = l2;
                l2 = l2->next;
            }
        }
        else if (!l2)
        {
            while (l1)
            {
                l3->next = l1;
                l3 = l1;
                l1 = l1->next;
            }
        }

        return Merged_list;
    }
};