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

// Brute force.
ListNode *removeNthFromEnd1(ListNode *head, int n)
{

    int i = 0, size = 0;

    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp != NULL)
    { // calculate size.
        size++;
        temp = temp->next;
    }
    n = size - n;

    if (n == 0)
    {
        head = head->next;
        return head;
    }

    temp = head;

    while (i < n)
    {
        i++;
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;

    return head;
}

// One Pass, without creating extra node.
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    { // case n = length of linked list.
        return head->next;
    }

    while (fast->next != NULL)
    {

        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}