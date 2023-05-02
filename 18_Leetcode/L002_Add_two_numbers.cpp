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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head1 = l1;
        ListNode *head2 = l2;

        ListNode *l3 = new ListNode(-1);
        ListNode *head3 = l3;

        int carry = 0;

        while (head1 && head2)
        {

            int sum = head1->val + head2->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            head3->next = new ListNode(value);

            head1 = head1->next;
            head2 = head2->next;
            head3 = head3->next;
        }

        while (head1)
        {

            int sum = head1->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            head3->next = new ListNode(value);

            head1 = head1->next;
            head3 = head3->next;
        }

        while (head2)
        {

            int sum = head2->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            head3->next = new ListNode(value);

            head2 = head2->next;
            head3 = head3->next;
        }

        while (carry)
        {

            head3->next = new ListNode(carry);
            break;
        }

        return l3->next;
    }
};