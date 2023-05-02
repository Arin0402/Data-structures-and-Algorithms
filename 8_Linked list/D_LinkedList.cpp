#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    // constructor to assign initial values to variables
    node()
    {
        next = NULL;
    }
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// using double pointer
void insertNodeAtStart(node **headref, int val)
{
    // cout<<(*headref)->data<<endl; //To access the starting node data
    node *new_node = new node();
    new_node->data = val;
    new_node->next = *headref;
    *headref = new_node;
}

// using single pointer
node *insertNodeAtStart_1(node *head)
{

    node *new_node = new node();
    new_node->data = 22;
    new_node->next = head;
    head = new_node;
    return head;
}
void insertAfter(node *prev_node, int val)
{

    node *new_node = new node();
    new_node->data = val;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void insertAtEnd(node **headref, int val)
{
    node *new_node = new node();
    node *last = *headref;
    new_node->data = val;
    new_node->next = NULL;

    if (*headref == NULL)
    {
        *headref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void Delete(node **headref, int key)
{

    node *temp = *headref;
    node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *headref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void push_1(node *head, int val)
{
    node *new_node = new node(val);
    node *temp = head;

    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}
void push(node **head, int val)
{
    cout << "inside" << endl;
    node *new_node = new node(val);
    node *temp = *head;

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    //   add element starting without function
    // node *new_node = new node();
    // new_node->data = 4;
    // new_node->next = head;
    // head = new_node;

    // add element after without function
    // node *new_node = new node();
    // new_node->data = 56;
    // new_node->next = head->next;
    // head->next = new_node;

    // add ele at end without function
    // node *new_node = new node();
    // node *last = head;
    // new_node->data = 45;
    // while (last->next != NULL)
    // {
    //     last = last->next;
    // }
    // last->next = new_node;

    insertNodeAtStart(&head, 11);
    insertAfter(head, 56);
    insertAtEnd(&head, 6);
    Delete(&head, 1);
    push(&head, 27);
    push_1(head, 28);
    print(head);

    return 0;
}