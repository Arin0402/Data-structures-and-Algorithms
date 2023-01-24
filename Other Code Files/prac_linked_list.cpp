#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;

    node(int val)
    {
        data = val;
    }
};

void insertatbeginning(node **temp, node *n)
{
    // cout << n << endl;
    // cout << temp << endl;
    // cout << (*temp)->data << endl;

    node *new_node = new node(22);

    new_node->next = *temp;
    *temp = new_node;
    // cout << *temp->data << endl;
}
node *insert_at_beginning(node *head)
{

    node *new_node = new node(22);
    new_node->next = head;
    head = new_node;
    return head;
}

void Delete(node **head, int key)
{

    node *q = *head;
    node *prev = NULL;

    while (q)
    {
        if (q->data == key && prev)
        {
            prev->next = q->next;
            delete q;
            return;
        }
        else if (q->data == key && prev == NULL)
        {

            *head = (*head)->next;
            delete q;
            return;
        }

        prev = q;
        q = q->next;
    }
}

void insertafter(node *head, int val)
{
    // node *new_node = new node(27);
    // node *q = *temp;

    // while (q)
    // {
    //     if (q->data == val)
    //     {
    //         new_node->next = q->next;
    //         q->next = new_node;
    //         return;
    //     }
    //     q = q->next;
    // }

    node *t = head;

    while (t)
    {
        if (t->data == val)
        {
            node *new_node = new node(435);
            new_node->next = t->next;
            t->next = new_node;
            return;
        }
        t = t->next;
    }
}
void insertatend(node **temp)
{

    node *new_node = new node(26);
    node *q = *temp;

    while (q->next)
        q = q->next;

    q->next = new_node;
}
node Delete_1(node *head)
{
    node *t = head;

    while (t->next)
    {
        t = t->next;
    }

    node *new_node = new node(27);
    t->next = new_node;

    return *head;
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

void push_at_end_using_last_node(node **last, int val)
{
    node *new_node = new node(val);

    (*last)->next = new_node;
    *last = new_node;
}

int main()
{

    node *first = new node(23);
    node *second = new node(24);
    node *third = new node(25);
    node *fourth = new node(26);

    first->next = second;
    second->next = third;
    third->next = fourth;

    // node *ptr_fourth = fourth;

    // push_at_end_using_last_node(&ptr_fourth, 27);
    // push_at_end_using_last_node(&ptr_fourth, 28);

    push(&first, 27);
    push_1(first, 28);

    while (first)
    {
        cout << first->data << endl;
        first = first->next;
    }
}
