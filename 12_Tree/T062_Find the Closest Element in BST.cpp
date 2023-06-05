#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// 1
// using refrence variable


class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
	void helper(Node* root, int k, int &ans){
	    
	    if(!root) return;
	    
        // calculate the minimum anaswer
	    ans = min(ans, abs(k - root->data));
	    
	    if(k == root->data){
	        ans = 0;
	        return;
	    }

        // if k is greater than root, then on the left we would only 
        //find elements less than root. So it will increase the difference.
        // hence go to right ot decrease the difference
	    else if(k > root->data){
	        helper(root->right, k, ans);
	    }

        // if k is lesser than root, then on the right we would only 
        // find elements greater than root. So it will increase the difference.
        // hence go to left ot decrease the difference
	    else helper(root->left, k, ans);
	    
	}
	
    int minDiff(Node *root, int K)
    {   
        
        int ans = INT_MAX;
        helper(root, K, ans);
        
        return ans;
    }
};

// 2
// without using refrence variable
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	
	int helper(Node* root, int k){
	    
	    if(!root) return INT_MAX;
	    
	    if(k == root->data) return 0;
	    
        // if k is greater than root, then on the left we would only 
        //find elements less than root. So it will increase the difference.
        // hence go to right ot decrease the difference
	    if(k > root->data) return min(abs(root->data - k), helper(root->right, k));

        // if k is lesser than root, then on the right we would only 
        // find elements greater than root. So it will increase the difference.
        // hence go to left ot decrease the difference
	    else return min(abs(root->data - k), helper(root->left, k));
	    
	}
	
    int minDiff(Node *root, int K)
    {   
        return helper(root, K);
    }
};
