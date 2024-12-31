// https://www.geeksforgeeks.org/generic-treesn-array-trees/

// The Generic trees are the N-ary trees which have the following properties:

//             1. Many children at every node.

//             2. The number of nodes for each node is not known in advance.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// worst approach
struct Node
{
    int data;
    struct Node *firstchild;
    struct Node *secondchild;
    struct Node *thirdchild;
    struct Node *fourthchild;
    struct Node *fifthchild;
    struct Node *sixthchild;
};

// better
struct Node
{
    int data;
    vector<Node *> links;
};

// best approach
struct Node
{
    int data;
    Node *firstChild;
    Node *nextSibling;
};

// https://leetcode.com/explore/learn/card/n-ary-tree/

// A binary tree is a rooted tree in which each node has no more than 2 children.
//  Let's extend this definition to N-ary tree. If a tree is a rooted tree in which each node has no more than N children,
//   it is called N-ary tree.

// Here is an example of 3-ary tree:

// Trie is one of the most frequently used N-ary trees.

// Also, a binary tree is a special form of a N-ary tree. In the following sections, we will extend what we have learned about binary trees to N-ary trees.