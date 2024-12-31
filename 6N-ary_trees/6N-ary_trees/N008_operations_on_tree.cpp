// https://leetcode.com/problems/operations-on-tree/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class LockingTree
{
public:
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> node_details;
    LockingTree(vector<int> &parent)
    {
        node_details.resize(parent.size(), vector<int>(2, -1));
        for (int i = 0; i < parent.size(); i++)
        {
            mp[parent[i]].push_back(i);
            node_details[i][0] = parent[i];
            node_details[i][1] = -1; // not locked
        }
    }

    bool lock(int num, int user)
    {
        if (node_details[num][1] != -1)
            return false;
        node_details[num][1] = user;
        return true;
    }

    bool unlock(int num, int user)
    {
        if (node_details[num][1] == -1 || node_details[num][1] != user)
            return false;
        node_details[num][1] = -1;
        return true;
    }

    bool checkDescendents(int num)
    {
        for (auto x : mp[num])
        {
            if (node_details[x][1] != -1)
                return true;
            if (checkDescendents(x))
                return true;
        }
        return false;
    }

    bool hasLockedAncestors(int num)
    {
        if (num == -1)
            return false;
        if (node_details[num][1] != -1)
            return true;
        return hasLockedAncestors(node_details[num][0]);
    }

    void unlockDescendents(int num)
    {
        for (auto x : mp[num])
        {
            node_details[x][1] = -1;
            unlockDescendents(x);
        }
    }

    bool upgrade(int num, int user)
    {
        if (node_details[num][1] != -1)
            return false;
        if (!checkDescendents(num))
            return false;
        if (hasLockedAncestors(node_details[num][0]))
            return false;
        unlockDescendents(num);
        lock(num, user);
        return true;
    }
};