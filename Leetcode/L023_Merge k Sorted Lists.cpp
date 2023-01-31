#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1;
// To merge the lists one by one
// TC - O(kN) N = total number of nodes.

// App. 2  
// using min heap to store the minimum elements.
// Tc = O(Nlogk)
// Sc = O(k)

class cmp
{

public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        int k = lists.size();

        for (int i = 0; i < k; i++)
        { // insert all the first elements of the lists.
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode *start = new ListNode(-1);
        ListNode *dummy = start;

        while (!pq.empty())
        {

            ListNode *temp = pq.top();
            pq.pop();

            if (temp->next)
                pq.push(temp->next); // push the next element of the top into queue.

            dummy->next = temp;
            dummy = temp;
        }

        return start->next;
    }
};