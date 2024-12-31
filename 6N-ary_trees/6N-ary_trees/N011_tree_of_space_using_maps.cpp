#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct DetailNode
{
    bool isLocked;
    int lockedBy;
    string parent;
    int des_locked = 0;
    int anc_locked = 0;

    DetailNode(string p)
    {
        isLocked = false;
        lockedBy = -1;
        parent = p;
    }
};

class Tree
{
private:
    unordered_map<string, vector<string>> mp;
    unordered_map<string, DetailNode *> detailMap;
    string root;

public:
    Tree()
    {
    }

    void buildTree(vector<string> &inp, int m)
    {
        int ind = 0;
        mp[inp[0]] = vector<string>();
        detailMap[inp[0]] = new DetailNode("");

        root = inp[0];

        int i = 1;
        while (i < inp.size() && ind < inp.size())
        {
            string node = inp[ind];
            int counter = m;
            while (i < inp.size() && counter--)
            {
                detailMap[inp[i]] = new DetailNode(node);
                mp[node].push_back(inp[i]);
                i++;
            }
            ind++;
        }
    }

    void printTree()
    {
        queue<string> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop();
                cout << "[" << curr << ", " << detailMap[curr]->parent << ", " << detailMap[curr]->lockedBy << ", " << detailMap[curr]->isLocked << "]";
                cout << "[" << detailMap[curr]->des_locked << ", " << detailMap[curr]->anc_locked << "]\t";

                for (auto x : mp[curr])
                {
                    q.push(x);
                }
            }
            cout << endl;
        }
    }

    void informParents(string s, int op)
    {
        string p = detailMap[s]->parent;
        while (p != "")
        {
            detailMap[p]->des_locked += op;
            p = detailMap[p]->parent;
        }
    }

    void informDesendents(string s, int op)
    {
        queue<string> q;
        q.push(s);

        while (!q.empty())
        {
            s = q.front();
            q.pop();
            for (auto x : mp[s])
            {
                detailMap[x]->anc_locked += op;
                q.push(x);
            }
        }
    }

    bool lock(string s, int uid)
    {
        DetailNode *d = detailMap[s];
        if (d->isLocked)
            return false;
        if (d->anc_locked != 0 || d->des_locked != 0)
            return false;
        informParents(s, 1);
        informDesendents(s, 1);

        d->isLocked = true;
        d->lockedBy = uid;
        return true;
    }

    bool unlock(string s, int uid)
    {
        DetailNode *d = detailMap[s];
        if (!d->isLocked)
            return false;
        if (d->isLocked && d->lockedBy != uid)
            return false;
        informParents(s, -1);
        informDesendents(s, -1);

        d->isLocked = false;
        d->lockedBy = -1;
        return true;
    }

    bool verifyDes(string s, int uid)
    {
        for (auto x : mp[s])
        {
            if (!detailMap[x]->isLocked || detailMap[x]->lockedBy != uid)
                return false;
            if (!verifyDes(x, uid))
                return false;
        }
        return true;
    }

    void unlockAllChildren(string s, int uid)
    {
        for (auto x : mp[s])
        {
            unlock(x, uid);
            unlockAllChildren(x, uid);
        }
    }

    bool upgrade(string s, int uid)
    {
        DetailNode *d = detailMap[s];
        if (d->isLocked)
            return false;
        if (d->anc_locked != 0 || d->des_locked == 0)
            return false;

        cout << "here\n";

        if (verifyDes(s, uid))
        {
            cout << "here" << endl;
            unlockAllChildren(s, uid);
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

        // cout << endl;
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