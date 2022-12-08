#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *sortedListToBSTRecur(Node **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;

    Node *left = sortedListToBSTRecur(head_ref, n / 2); // go to extreme left as it is sorted .

    Node *root = *head_ref; // make root as starting of the linked list.

    root->left = left; // make it left subtree.

    *head_ref = (*head_ref)->right; // move the pointer in linked list.

    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

    return root;
}