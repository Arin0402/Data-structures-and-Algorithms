#include <bits/stdc++.h>
using namespace std;

// TO UNDERSTAND HUFFMAN ENCODING
// https://www.youtube.com/watch?v=uDS8AkTAcIU

// TO UNDERSTAND HOW TO SOLVE.
// Love babbar's greedy algorithm video.
// https://youtu.be/HZOUwKCKF5o?t=2923

// Node class
class Node
{
public:
	int data;

	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// comparator class.
class cmp
{

public:
	bool operator()(Node *a, Node *b)
	{

		// Note - we use < operator for sorting in increasing order but
		// in the case of min heap it is  >.
		return a->data > b->data;
	}
};

class Solution
{
public:
	// preorder traversal for the tree.
	void traverse(Node *root, vector<string> &ans, string code)
	{

		if (!root->left && !root->right)
		{
			ans.push_back(code);
			return;
		}

		traverse(root->left, ans, code + '0');
		traverse(root->right, ans, code + '1');
	}

	vector<string> huffmanCodes(string S, vector<int> f, int N)
	{

		// min heap.
		priority_queue<Node *, vector<Node *>, cmp> pq;

		// push all the frequencies in the priority queue.
		for (int i = 0; i < N; i++)
		{

			Node *newNode = new Node(f[i]);
			pq.push(newNode);
		}

		// just like minimum cost of ropes problem.

		while (pq.size() > 1)
		{

			Node *left = pq.top(); // first minimum element.
			pq.pop();

			Node *right = pq.top(); // second minimum element.
			pq.pop();

			// this will create a tree.
			// see the tree image upside down for more understanding.
			Node *newNode = new Node(left->data + right->data);

			newNode->left = left;
			newNode->right = right;

			pq.push(newNode);
		}

		// traverse the tree to assign codes.
		Node *root = pq.top();

		vector<string> ans;

		traverse(root, ans, "");

		return ans;
	}
};