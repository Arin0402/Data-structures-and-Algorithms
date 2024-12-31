// https://leetcode.com/discuss/interview-question/1279262/juspay-tree-of-space-locking-and-unlocking-n-ary-tree
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
    string data;
    vector<Node *> children;
    bool locked = false;
    Node *parent;
    int anc_locked = 0, dec_locked = 0;
    int lockedBy;

    Node()
    {
        data = "";
        locked = false;
        anc_locked = 0;
        dec_locked = 0;
        lockedBy = -1;
        parent = NULL;
    }

    Node(string val)
    {
        data = val;
        locked = false;
        anc_locked = 0;
        dec_locked = 0;
        lockedBy = -1;
        parent = NULL;
    }

    void addChildren(Node *node)
    {
        node->parent = this;
        children.push_back(node);
    }
};

class Tree
{
private:
    Node *root;
    unordered_map<string, Node *> mp;

public:
    Tree()
    {
        root = new Node();
    }

    void initRoot(string s)
    {
        root->data = s;
        mp[s] = root;
    }

    void buildTree(vector<string> &inp, int m)
    {
        initRoot(inp[0]);
        Node *node = root;
        queue<Node *> q;
        q.push(node);

        int i = 1;
        while (i < inp.size())
        {
            node = q.front();
            q.pop();
            int counter = m;
            while (i < inp.size() && counter > 0)
            {
                Node *child = new Node(inp[i]);
                node->addChildren(child);
                q.push(child);
                mp[inp[i]] = child;
                counter--;
                i++;
            }
        }
    }

    void printTree()
    {
        Node *node = root;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                node = q.front();
                q.pop();
                cout << "{" << node->data << " " << (node->parent ? node->parent->data : "");
                printf(" %d, %d, %d}\t", node->anc_locked, node->dec_locked, node->locked);

                for (auto x : node->children)
                {
                    q.push(x);
                }
            }

            cout << endl;
        }
    }

    Node *search(string s)
    {
        return mp[s];
    }

    void informChildren(Node *node, int op)
    {
        for (auto x : node->children)
        {
            x->anc_locked += op;
            informChildren(x, op);
        }
    }

    bool lock(string s, int uid)
    {
        Node *node = search(s);
        if (node->locked)
            return false;
        if (node->anc_locked != 0 || node->dec_locked != 0)
            return false;

        node->locked = true;
        node->lockedBy = uid;

        Node *p = node->parent;
        while (p != NULL)
        {
            p->dec_locked++;
            p = p->parent;
        }

        informChildren(node, 1);
        return true;
    }

    bool unlock(string s, int uid)
    {
        Node *node = search(s);
        if (!node->locked)
            return false;
        if (node->locked && node->lockedBy != uid)
            return false;

        node->locked = false;
        node->lockedBy = -1;

        Node *p = node->parent;
        while (p != NULL)
        {
            p->dec_locked--;
            p = p->parent;
        }

        informChildren(node, -1);
        return true;
    }

    bool verifyChildren(Node *node, int uid)
    {
        // 1) method 1
        //  if (node->locked)
        //  {
        //      if (node->lockedBy != uid)
        //          return false;
        //  }
        //  for (auto x : node->children)
        //  {
        //      if (!verifyChildren(x, uid))
        //      {
        //          return false;
        //      }
        //  }
        //  return true;

        // 2) method 2
        for (auto x : node->children)
        {
            if (x->locked && x->lockedBy != uid)
                return false;
            if (!verifyChildren(x, uid))
            {
                return false;
            }
        }
        return true;
    }

    void unlockAllChildren(Node *node, int uid)
    {
        for (auto x : node->children)
        {
            unlock(x->data, uid);
            unlockAllChildren(x, uid);
        }
    }

    bool upgrade(string s, int uid)
    {
        Node *node = search(s);
        if (node->locked)
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