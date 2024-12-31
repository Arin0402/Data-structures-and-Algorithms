// https://leetcode.com/problems/throne-inheritance/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

// mine solution working fine -similar to n-array question that was asked in juspay

struct TreeNodeString
{
    string val;
    bool isDead = false;
    vector<TreeNodeString *> children;
    TreeNodeString(string val)
    {
        this->val = val;
    }
};

class ThroneInheritance
{
private:
    TreeNodeString *root;
    unordered_map<string, TreeNodeString *> mp;

public:
    ThroneInheritance(string kingName)
    {
        root = new TreeNodeString(kingName);
        mp[kingName] = root;
    }

    void birth(string parentName, string childName)
    {
        TreeNodeString *child = new TreeNodeString(childName);
        mp[parentName]->children.push_back(child);
        mp[childName] = child;
    }

    void death(string name)
    {
        mp[name]->isDead = true;
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> res;
        get(res, root);
        return res;
    }

    void get(vector<string> &res, TreeNodeString *root)
    {
        if (!root->isDead)
            res.push_back(root->val);
        for (auto x : root->children)
        {
            get(res, x);
        }
    }
};

// another way of writing above solution
class ThroneInheritance
{
public:
    string root = "";
    unordered_set<string> st;
    unordered_map<string, vector<string>> mp;
    ThroneInheritance(string kingName)
    {
        root = kingName;
    }

    void birth(string parent, string child)
    {
        mp[parent].push_back(child);
    }

    void death(string name)
    {
        st.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> v;
        fun(root, v);
        return v;
    }
    void fun(string root, vector<string> &v)
    {
        if (st.find(root) == st.end())
            v.push_back(root);

        for (string child : mp[root])
            fun(child, v);
    }
};
