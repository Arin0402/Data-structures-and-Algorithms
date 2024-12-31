// 1) don't check anything before setting
// 2) one count,  one boolean
// 3) check the count variable before the while loop.
// 4) check the bool var inside the while loop.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

struct Node
{
    string data;
    bool locked = false;
    int lockedBy, dec_count = 0;
    vector<Node *> children;
    Node *parent;
    unordered_set<Node *> lockedDescendents;
    bool isInUse = false;
    int count = 0;

    Node()
    {
        parent = NULL;
        data = "";
        lockedBy = -1;
    }
    Node(string val)
    {
        data = val;
        parent = NULL;
        lockedBy = -1;
    }

    void push(Node *node)
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

    void initRoot(string s)
    {
        root->data = s;
        mp[s] = root;
    }

public:
    Tree()
    {
        root = new Node();
    }

    void buildTree(vector<string> &nodeNames, int m)
    {
        initRoot(nodeNames[0]);
        Node *node = root;

        queue<Node *> q;
        q.push(node);
        int i = 1;

        while (i < nodeNames.size())
        {
            node = q.front();
            q.pop();
            int counter = m;
            while (i < nodeNames.size() && counter > 0)
            {
                node->push(new Node(nodeNames[i]));
                q.push(node->children.back());
                mp[nodeNames[i]] = node->children.back();
                counter--;
                i++;
            }
        }
    }

    bool lock(string nodename, int userId)
    {
        Node *node = mp[nodename];
        node->count++;
        node->isInUse = true;
        // thread one stops here

        if (node->locked || node->dec_count != 0 || node->count > 1)
        {
            node->count--;
            return false;
        }

        Node *p = node->parent;
        vector<Node *> usedNodes;

        while (p != NULL)
        {
            p->count += 1;
            usedNodes.push_back(p);
            if (p->isInUse || p->locked)
            {
                for (auto x : usedNodes)
                    x->count -= 1;
                node->isInUse = false;
                //
                node->count--;
                return false;
            }
            p = p->parent;
        }

        p = node->parent;
        while (p != NULL)
        {
            p->dec_count++;
            p->count -= 1;
            p->lockedDescendents.insert(node);
            p = p->parent;
        }

        node->locked = true;
        node->lockedBy = userId;
        node->isInUse = false;
        return true;
    }

    bool unlock(string nodename, int userId)
    {
        Node *node = mp[nodename];
        if (!node->locked)
            return false;
        if (node->locked && node->lockedBy != userId)
            return false;

        Node *p = node->parent;
        while (p != NULL)
        {
            p->dec_count--;
            p->lockedDescendents.erase(node);
            p = p->parent;
        }

        node->locked = false;
        node->lockedBy = -1;
        return true;
    }

    bool checkIfDescendentsAreLockedBySameUser(Node *node, int userId)
    {
        for (auto x : node->lockedDescendents)
        {
            if (x->lockedBy != userId)
                return false;
        }
        return true;
    }

    void unlockAllDescendents(Node *node, int userId)
    {
        for (auto x : node->lockedDescendents)
        {
            unlock(x->data, userId);
        }
    }

    bool upgradeLock(string nodename, int userId)
    {
        Node *node = mp[nodename];
        if (node->locked || node->dec_count == 0)
            return false;

        if (checkIfDescendentsAreLockedBySameUser(node, userId))
        {
            unlockAllDescendents(node, userId);
        }
        else
        {
            return false;
        }

        lock(nodename, userId);
        return true;
    }
};

int main()
{
    int n;                    // number of nodes
    int m;                    // number of children per node
    int q;                    // number of queries
    vector<string> nodeNames; // all node names

    cin >> n >> m >> q;
    ;
    string curr_name;
    for (int i = 0; i < n; i++)
    {
        cin >> curr_name;
        nodeNames.push_back(curr_name);
    }

    Tree t;
    t.buildTree(nodeNames, m);
    // t.printTree();
    // above functions are working fine

    int operationType, userId;
    string nodeName;
    for (int i = 0; i < q; i++)
    {
        cin >> operationType >> nodeName >> userId;

        bool ans = false;
        switch (operationType)
        {
        case 1:
            ans = t.lock(nodeName, userId);
            break;
        case 2:
            ans = t.unlock(nodeName, userId);
            break;
        case 3:
            ans = t.upgradeLock(nodeName, userId);
            break;
        }
        // t.printTree();
        // cout<<endl;
        cout << (ans ? "true" : "false") << endl;
    }

    return 0;
}