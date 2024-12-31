// https://practice.geeksforgeeks.org/problems/k-sum-paths/1
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
    void Helper(Node *root, int k, int &ans, vector<int> &path)
    {

        if (!root)
            return;

        path.push_back(root->data);

        Helper(root->left, k, ans, path);
        Helper(root->right, k, ans, path);

        int sum = 0;

        for (int i = path.size() - 1; i >= 0; i--)
        { // traverse from the bck side of the vector.

            sum += path[i];

            if (sum == k)
                ans++;
        }

        path.pop_back(); // remove the last element of the vector.
    }

    int sumK(Node *root, int k)
    {

        if (!root)
            return 0;

        int ans = 0;
        vector<int> path; // store all the nodes from top to bottom.

        Helper(root, k, ans, path);

        return ans;
    }
};

// or using map

class Solution {
  public:
  
    unordered_map<int, int> mp;
    
    void helper(Node* root, int &ans, int &sum, int k){
        
        if(!root) return;
        
        sum += root->data;
        if(mp.find(sum - k) != mp.end()) ans += mp[sum - k];
        
        mp[sum]++;
        
        helper(root->left, ans, sum, k);
        helper(root->right, ans, sum, k);
        
        mp[sum]--;
        sum -= root->data;
        
    }
  
    int sumK(Node *root, int k) {
        
        int ans = 0;
        int sum = 0;
        
        mp[0] = 1;
        
        helper(root, ans, sum, k);
        
        return ans;
    }
};