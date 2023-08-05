#include <bits/stdc++.h>
using namespace std;

// node decleration
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative Pre Order Traversal. TC - O(n), SC - O(n).
vector<int> preorder(TreeNode *root)
{

    vector<int> ans;

    if (!root)
        return ans;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {

        root = s.top();

        ans.push_back(root->val);
        s.pop();

        if (root->right)
            s.push(root->right); // First right then left.
        if (root->left)
            s.push(root->left);
    }

    return ans;
}

// Iterative Inorder Traversal TC - O(n), SC - O(n).
vector<int> inOrder(TreeNode *root)
{

    vector<int> ans;

    if (!root)
        return ans;

    stack<TreeNode *> s;

    while (true)
    {

        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {

            if (s.empty())
                break;

            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }

    return ans;
}

// Iterative PostOrder Traversal
// It is just the reverse of the preorder traversal

vector <int> postOrder(TreeNode* root)
{
    vector<int> ans;
    
    stack<TreeNode*> st;
    
    st.push(root);
    
    
    while(!st.empty()){
        
        auto p = st.top();
        st.pop();
        
        ans.push_back(p->val);
        
        if(p->left) st.push(p->left);
        if(p->right) st.push(p->right);
        
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}


// Iterative PostOrder Traversal using 2 stacks. TC - O(n), SC - O(2n).
vector<int> postOrder(TreeNode *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    stack<TreeNode *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();

        s2.push(root);

        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->val);
        s2.pop();
    }

    return ans;
}

// Iterative PostOrder Traversal using 1 stack. TC - O(2n), SC - O(n).
vector<int> postOrder(TreeNode *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    stack<TreeNode *> s;

    while (root || !s.empty())
    {

        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {

            TreeNode *temp = s.top()->right;

            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);

                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                }
            }
            else
            {
                root = temp;
            }
        }
    }

    return ans;
}