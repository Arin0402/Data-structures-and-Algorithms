#include <bits/stdc++.h>
using namespace std;

// Approach 1;
// To merge the lists one by one
// TC - O(kN) N = total number of nodes.

// App. 2  
// using min heap to store the minimum elements.
// Tc = O(Nlogk)
// Sc = O(k)

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
 
class cmp
{
    public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{

public:
    Node *mergeKLists(Node* lists[], int k)
    {

        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (int i = 0; i < k; i++)
        { // insert all the first elements of the lists.
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        Node *start = new Node(-1);
        Node *dummy = start;

        while (!pq.empty())
        {

            Node *temp = pq.top();
            pq.pop();

            if (temp->next)
                pq.push(temp->next); // push the next element of the top into queue.

            dummy->next = temp;
            dummy = temp;
        }

        return start->next;
    }
};