#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

void convertIntoDoublyLinkedList(TreeNode *root, TreeNode **head, TreeNode **prev)
{

    if (!root)
        return;

    convertIntoDoublyLinkedList(root->left, head, prev);

    if (*prev == NULL)
        *head = root;
    else
    {
        (*prev)->right = root;
        root->left = *prev;
    }

    *prev = root;

    convertIntoDoublyLinkedList(root->right, head, prev);
}

TreeNode *MergeLinkedLists(TreeNode *root1, TreeNode *root2)
{

    if (!root1)
        return root2;
    if (!root2)
        return root1;

    TreeNode *head = new TreeNode(-1);
    TreeNode *dummy = head;
    TreeNode *head1 = root1;
    TreeNode *head2 = root2;

    while (head1 && head2)
    {

        if (head1->data < head2->data)
        {
            dummy->right = head1;
            head1->left = dummy;
            head1 = head1->right;
            dummy = dummy->right;
        }
        else
        {
            dummy->right = head2;
            head2->left = dummy;
            head2 = head2->right;
            dummy = dummy->right;
        }
    }

    while (head1)
    {

        dummy->right = head1;
        head1->left = dummy;
        head1 = head1->right;
        dummy = dummy->right;
    }

    while (head2)
    {

        dummy->right = head2;
        head2->left = dummy;
        head2 = head2->right;
        dummy = dummy->right;
    }

    head->right->left = NULL;
    return head->right;
}

int countNodes(TreeNode *head)
{

    int count = 0;
    TreeNode *tmp = head;

    while (tmp)
    {
        count++;
        tmp = tmp->right;
    }
    return count;
}
TreeNode *convertIntoBst(TreeNode **head, int n)
{

    if (n <= 0 || *head == NULL)
        return NULL;

    TreeNode *left = convertIntoBst(head, n / 2);
    TreeNode *root = *head;

    root->left = left;

    *head = (*head)->right;

    root->right = convertIntoBst(head, n - n / 2 - 1);

    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    // conversion into douby linked list.
    TreeNode *prev = NULL;

    TreeNode *head1 = NULL;
    TreeNode *head2 = NULL;

    convertIntoDoublyLinkedList(root1, &head1, &prev);
    prev = NULL;
    convertIntoDoublyLinkedList(root2, &head2, &prev);

    // Merge sorted linked lists.
    TreeNode *start = MergeLinkedLists(head1, head2);

    // convert into BST.
    int n = countNodes(start);
    return convertIntoBst(&start, n);
}