#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-linked-list/

struct Node
{
    int data;
    struct Node *next;
};


void deleteNodeWithoutHead(struct Node *pos)
{
    if (pos == NULL) 
        return;
    else
    {
        
        struct Node *temp = pos->next;

        // Copy data of the next node to current node
        pos->data = pos->next->data;

        // Perform conventional deletion
        pos->next = pos->next->next;

        free(temp);
    }
}
