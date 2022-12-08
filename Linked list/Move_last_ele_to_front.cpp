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

void push(node **head, int val)
{
    node *new_node = new node(val);
    new_node->next = *head;
    *head = new_node;
}

void print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
node *moveToFront(node *head)
{

    node *last = head;
    node *sec_last = head;

    while (last->next)
    {
        sec_last = last;
        last = last->next;
    }
    sec_last->next = NULL;
    last->next = head;

    return last;
}

void moveToFront_1(node **head)
{
    node *last = *head;
    node *sec_last = *head;

    while (last->next)
    {
        sec_last = last;
        last = last->next;
    }
    sec_last->next = NULL;
    last->next = *head;
    *head = last;
}
int main()
{
    node *start = NULL;

    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    // start = moveToFront(start);
    moveToFront_1(&start);
    print(start);
}