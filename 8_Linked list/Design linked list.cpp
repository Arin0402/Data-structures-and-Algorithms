//  https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1211
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class MyLinkedList
{
public:
    Node *head;
    int n;
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        n = 0;
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= n || index < 0)
            return -1;
        Node *temp = head;
        while (index > 0)
        {
            index--;
            temp = temp->next;
        }
        return temp->data;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        n++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        n++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > n)
            return;
        if (index == n)
        {
            addAtTail(val);
        }
        else if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            Node *temp = head;
            Node *newnode = new Node(val);
            int i = 1;
            while (i != index)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            n++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= n)
        {
            return;
        }
        Node *temp;
        if (index == 0)
        {
            temp = head;
            head = head->next;
            temp->next = NULL;
        }
        else
        {
            temp = head;
            int i = 1;
            while (i != index)
            {
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
        }
        n--;
    }
};
int main()
{

    return 0;
}