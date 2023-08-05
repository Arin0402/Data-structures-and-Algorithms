#include<bits/stdc++.h>
using namespace std;

class LockingTree {
public:

    vector<int> parent;
    vector<int> locked;
    unordered_map<int, vector<int>> children;

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();        

        // initialise the locked vector
        vector<int> temp(n, -1);
        locked = temp;

        // parent child relationship
        for(int i = 1; i < n; i++){
            children[parent[i]].push_back(i);
        }
    }

    bool isAncestorLocked(int num) {
        int curr = num;
        while (curr != -1) {
            if (locked[curr] != -1) {
                return true;
            }
            curr = parent[curr];
        }
        return false;
    }

    bool areDescendantsLocked(int num) {
        queue<int> q;
        q.push(num);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (locked[node] != -1) {
                return true;
            }

            for (auto ele : children[node]) {
                q.push(ele);
            }
        }
        return false;
    }

    bool lock(int num, int user) {

        // Check if any ancestor or descendant is locked
        if (isAncestorLocked(num) || areDescendantsLocked(num)) {
            return false;
        }

        // Node is not locked yet, so lock it
        locked[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        // can not unlock
        if (locked[num] != user) {
            return false;
        } else {
            locked[num] = -1;
            return true;
        }
    }

    bool upgrade(int num, int user) {
        // check for ancestors
        int curr = num;
        while (curr != -1) {
            // current node is locked
            if (locked[curr] != -1) {
                return false;
            }
            curr = parent[curr];
        }

        // check for descendants
        int lockedcount = 0;        
        queue<int> q;
        q.push(num);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // node is locked so unlock it
            if (locked[node] != -1) {
                locked[node] = -1;
                lockedcount++;
            }

            for (auto ele : children[node]) {
                q.push(ele);
            }
        }

        // possible to lock
        if (lockedcount > 0) {        
            locked[num] = user;
            return true;
        } else {
            return false;
        }
    }
};
