#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
};
void Reverse(node **head)
{
    node *prev = NULL;
    node *curr = *head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void push(node **head, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void print(node **head)
{

    node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = new node();
    head->data = 1;
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    cout << "Before Reversing " << endl;
    print(&head);
    cout << "After Reversing " << endl;
    Reverse(&head);
    print(&head);
}