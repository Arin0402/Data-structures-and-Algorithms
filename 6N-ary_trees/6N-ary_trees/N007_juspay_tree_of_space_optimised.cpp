#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <mutex>

using namespace std;

struct TreeNode
{
    string data = "";
    vector<TreeNode *> children;
    TreeNode *parent = NULL;
    bool isLocked = false;
    int anc_locked = 0, dec_locked = 0, uid = -1;

    TreeNode(string data)
    {
        this->data = data;
    }
};

class Tree
{
private:
    TreeNode *root;
    unordered_map<string, TreeNode *> mp;
    mutex mtx;

public:
    void buildTree(vector<string> &inp, int m)
    {
        root = new TreeNode(inp[0]);
        mp[inp[0]] = root;

        TreeNode *node = root;
        queue<TreeNode *> q;
        q.push(node);

        int i = 1;
        while (!q.empty() && i < inp.size())
        {
            node = q.front();
            q.pop();
            int counter = m;

            while (i < inp.size() && counter > 0)
            {
                TreeNode *child = new TreeNode(inp[i]);
                child->parent = node;
                node->children.push_back(child);
                q.push(child);
                mp[inp[i]] = child;
                i++;
                counter--;
            }
        }
    }

    void printTree()
    {
        TreeNode *node = root;
        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                node = q.front();
                q.pop();

                cout << "{" << node->data << " " << (node->parent ? node->parent->data : "None");
                cout << node->anc_locked << " " << node->dec_locked << " " << node->isLocked;
                cout << "\t";

                for (auto x : node->children)
                {
                    q.push(x);
                }
            }

            cout << endl;
        }
    }

    void informChildren(TreeNode *root, int op)
    {
        for (auto x : root->children)
        {
            x->anc_locked += op;
            informChildren(x, op);
        }
    }

    bool lock(string s, int uid)
    {
        TreeNode *node = mp[s];

        if (node->isLocked)
            return false;
        if (node->anc_locked != 0 || node->dec_locked != 0)
            return false;

        mtx.lock();
        node->isLocked = true;
        node->uid = uid;

        TreeNode *p = node->parent;
        while (p != NULL)
        {
            p->dec_locked++;
            p = p->parent;
        }

        informChildren(node, 1);
        mtx.unlock();
        return true;
    }

    bool unlock(string s, int uid)
    {
        TreeNode *node = mp[s];
        if (!node->isLocked)
            return false;
        if (node->isLocked && node->uid != uid)
            return false;

        mtx.lock();
        node->isLocked = false;
        node->uid = -1;

        TreeNode *p = node->parent;
        while (p != NULL)
        {
            p->dec_locked--;
            p = p->parent;
        }

        informChildren(root, -1);
        mtx.unlock();
        return true;
    }

    bool verifyChildren(TreeNode *node, int uid)
    {
        for (auto x : node->children)
        {
            if (!x->isLocked || x->uid != uid)
                return false;
            if (!verifyChildren(x, uid))
                return false;
        }

        return true;
    }

    void unlockAllChildren(TreeNode *node, int uid)
    {
        for (auto x : node->children)
        {
            unlock(x->data, uid);
            unlockAllChildren(x, uid);
        }
    }

    bool upgrade(string s, int uid)
    {
        TreeNode *node = mp[s];
        if (node->isLocked)
            return false;
        if (node->anc_locked != 0 || node->dec_locked == 0)
            return false;

        if (verifyChildren(node, uid))
        {
            unlockAllChildren(node, uid);
        }
        else
        {
            return false;
        }

        lock(s, uid);
        return true;
    }
};

int main()
{
    /*
     * INPUT
     * n = total number of nodes
     * m = number of child per node
     * q = number of queries
     *
     * next 'n' lines = node name in string
     * next 'q' lines = queries with (opcode, string, uid)
     *
     * opcode => 1 = Lock, 2 = Unlock, 3 = Upgrade
     */

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }

    Tree t;
    t.buildTree(inp, m);
    t.printTree();

    int op, uid;
    string s;
    while (q--)
    {
        cin >> op >> s >> uid;
        bool ans = false;
        switch (op)
        {
        case 1:
            ans = t.lock(s, uid);
            break;
        case 2:
            ans = t.unlock(s, uid);
            break;
        case 3:
            ans = t.upgrade(s, uid);
            break;
        }

        cout << endl;
        t.printTree();
        cout << (ans ? "true" : "false") << endl;
    }

    return 0;
}

/*
Example Input:
7
2
4
World
Asia
Africa
India
China
SouthAfrica
Egypt
1 China 9
1 India 9
3 Asia 9
2 India 9
*/

// OPTIMISATION POINTS
// 1) Code without any structs or tree node -- see NO08
// 2) Yes, your mentor will be asking to convert all the three functions into a specific time complexity, and then he will ask you to make it working for the multi threading environment.
// Lock and unlock can be approached easily into O(logN) but for update you have to work hard.

// i have uploaded the thread safety code also and it has same logic as mention by this comment but i have also
// include on how to use this boolean variable to make all three operation as thread safe. The question if
// not how to run operation with thread but just to make them thread safe meaning no need to use thread
// library or any kind of extra library

// i have uploaded the thread safety code also and it has same logic as mention by this comment but i have also include
// on how to use this boolean variable to make all three operation as thread safe. The question if not how to run operation
//  with thread but just to make them thread safe meaning no need to use thread library or any kind of extra library

// yaa you are on correct path. We have to do something similar and then think of a way to make operations wait if any
//  of the resource is in use and then continue its work if the resource gets free. Unfortunately I will not be able to
//  explain full tricks and solution. and ya i was able to clear Part B and interview

// Think in terms of semaphore making other threads wait till the resource gets free

// The easiest solution for making any code thread safe is always check if resource is in use or not in each situation like updating value to variable ( to avoid race Condition ) and while accessing value of variable (to avoid deadlocks)