#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

// 1
// This solution is generally not acceptyed in the interviews

void makeParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
{

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        TreeNode *curr = q.front();
        q.pop();

        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> parent_track;

    makeParent(root, parent_track); // store parent of current node.

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;

    visited[target] = true;
    q.push(target);

    int distance = 0;

    while (!q.empty())
    {

        int size = q.size();

        if (distance == k)
            break;
        distance++;

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent_track[curr] && !visited[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
    }

    vector<int> result;

    while (!q.empty())
    {

        TreeNode *curr = q.front();
        q.pop();

        result.push_back(curr->data);
    }

    return result;
}

// 2
// wiothout marking parent pointers

class Solution {
public:

    // program to find the nodes which are at a distance k from the current node
    // in it's subtree i.e in hte downward direction
    void allTheNodesAtDistanceK(TreeNode* root, int k, vector<int> &ans){

        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;

        // level order traversal
        while(!q.empty()){
            
            // insert all the nodes of the current level
            if(lvl == k){

                while(!q.empty()){
                    TreeNode* temp = q.front();
                    q.pop();

                    ans.push_back(temp->data);
                }

                break;
            }

            int n = q.size();

            for(int i = 0; i < n; i++){

                TreeNode* temp = q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            lvl++;
        }

    }

    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &ans){

        // return a large value such that we can know that the answer is not present in this part
        if(!root) return 1e9;

        // current node is the target. print it's subtree nodes
        if(root == target){
            allTheNodesAtDistanceK(root, k, ans);
            return 0;
        }

        // go left
        int left = helper(root->left, target, k, ans);  
        // go right
        int right = helper(root->right, target, k, ans);

        // compute the distance from the target.
        int mydist = min(left, right) + 1;

        // found the target in the left subtree. so we have to print the nodes of the right subtree of the current node. so print the nodes which are at the distance k - mydist - 1 from the current_node->right
        if(left < 1e9) allTheNodesAtDistanceK(root->right, k - mydist - 1, ans);
        else if(right < 1e9) allTheNodesAtDistanceK(root->left, k - mydist - 1, ans);

        // current node is at the distance k from the target
        if(mydist == k){
            ans.push_back(root->data);
        }

        return mydist;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        helper(root, target, k, ans);

        return ans;
        
    }
};