#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

node *insertAtStart(node *head, int n)
{

    node *new_node = new node(n);
    new_node->next = head;
    head = new_node;
    return head;
}
void insertAtStart_1(node **head, int n)
{
    node *new_node = new node(n);
    new_node->next = *head;
    *head = new_node;
}
void Delete(node **head, int val)
{

    cout << "Delete called" << endl;
    node *temp = *head;

    while (temp)
    {
        if (temp->data == val)
        {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            delete temp;
            break;
        }
        temp = temp->next;
    }

    // return head;
}

int main()
{

    node *first = new node(1);
    node *second = new node(2);
    node *third = new node(3);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    node *temp = insertAtStart(first, 0);

    Delete(&first, 2);

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}