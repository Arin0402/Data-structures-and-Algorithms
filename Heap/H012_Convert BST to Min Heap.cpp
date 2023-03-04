#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/_9F2VgZcvdw?t=3362/
// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=1

// 1
// Given that the binary tree is complete so the the structure would remain same.
// find the inorder of the bst, it will be sorted
// now for min heap we two conditions
// root < L and root < R
// and in the sorted vector we have L < R
// SO we conclude that root < L < R.
// this is preorder so will traverse the tree in preorder form and update the values of the node.
// we take a variable index which will point the index of the sorted vector.

// O(n) for all the operations.
class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};

void inorder(BinaryTreeNode* root, vector<int> &ans){

	if(!root) return;

	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);

}

// populate the current tree using preorder.
void preorder(BinaryTreeNode* root, int &i, vector<int> &ans){

	if(!root) return ;
	root->data = ans[i++];

	preorder(root->left, i, ans);
	preorder(root->right, i, ans);

}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// find inorder
	vector<int> ans;
	inorder(root, ans);

	int i = 0;
	preorder(root , i , ans);

	return root;
}