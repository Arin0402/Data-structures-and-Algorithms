#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  Preorder Inorder Postorder Traversals in One Traversal
vector<int> traversal(TreeNode *root)
{

    stack<pair<TreeNode *, int>> st;
    vector<int> pre, in, post;

    st.push({root, 1});

    if (root == NULL)
        return;

    while (!st.empty())
    {

        auto tp = st.top();
        st.pop();

        // First time visit so preorder.
        // increment 1 to 2.
        // push back into stack.
        // if there is left child, then push it also into stack.

        if (tp.second == 1)
        {

            pre.push_back(tp.first->val);
            tp.second++;
            st.push(tp);

            if (tp.first->left)
            {
                st.push({tp.first->left, 1});
            }
        }

        // second time visit so inorder.
        // increase 2 to 3;
        else if (tp.second == 2)
        {
            in.push_back(tp.first->val);
            tp.second++;
            st.push(tp);

            if (tp.first->right)
            {
                st.push({tp.first->right, 1});
            }
        }

        // third time visit so postorder.
        // this time no push back.
        else
        {

            post.push_back(tp.first->val);
        }
    }