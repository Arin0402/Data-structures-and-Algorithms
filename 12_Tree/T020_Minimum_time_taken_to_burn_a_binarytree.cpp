#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Node **targetNode -> this can be single pointer also
void makeParent(Node *root, unordered_map<Node *, Node *> &parent_tracker, int target, Node **targetNode)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        if (curr->data == target)
            *targetNode = curr;

        if (curr->left)
        {
            q.push(curr->left);
            parent_tracker[curr->left] = curr;
        }
        if (curr->right)
        {
            q.push(curr->right);
            parent_tracker[curr->right] = curr;
        }
    }
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parent_tracker;

    Node *targetNode; // Identify target node using value.

    makeParent(root, parent_tracker, target, &targetNode); // keep parent pointers , same as previous question.

    unordered_map<Node *, bool> visited;
    queue<Node *> q;

    visited[targetNode] = true;
    q.push(targetNode);

    int time = 0;
    while (!q.empty())
    {

        int size = q.size();

        bool flag = false;

        for (int i = 0; i < size; i++)
        {

            Node *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                visited[curr->left] = true;
                q.push(curr->left);
                flag = true;
            }
            if (curr->right && !visited[curr->right])
            {
                visited[curr->right] = true;
                q.push(curr->right);
                flag = true;
            }
            if (parent_tracker[curr] && !visited[parent_tracker[curr]])
            {
                visited[parent_tracker[curr]] = true;
                q.push(parent_tracker[curr]);
                flag = true;
            }
        }

        if (flag)
        {
            time++;
        }
    }

    return time;
}