// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
// https://www.geeksforgeeks.org/count-pairs-from-two-bsts-whose-sum-is-equal-to-a-given-value-x/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    int countPairs(Node *root1, Node *root2, int x)
    {

        int count = 0;

        if (!root1 || !root2)
            return 0;

        stack<Node *> s1, s2;

        Node *top1 = root1;
        Node *top2 = root2;

        while (true)
        {

            while (root1)
            { // go to extreme left in first bst.
                s1.push(root1);
                root1 = root1->left;
            }

            while (root2)
            { // go to exrteme right in second bst.
                s2.push(root2);
                root2 = root2->right;
            }

            if (s1.empty() || s2.empty())
                break; // base case. // iteration complete

            top1 = s1.top();
            top2 = s2.top();

            if (top1->data + top2->data == x)
            {

                count++;

                s1.pop();
                s2.pop();

                root1 = top1->right; // move right i.e increase the value , then it will go to left again ( while loop for root1 at top)
                root2 = top2->left;
            }
            else if (top1->data + top2->data < x)
            {

                s1.pop();
                root1 = top1->right; // increase the value.
            }
            else
            {
                s2.pop();
                root2 = top2->left;
            }
        }

        return count;
    }
};