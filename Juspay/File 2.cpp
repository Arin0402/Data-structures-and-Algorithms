
vector<int> parent;
vector<int> locked;
unordered_map<int, vector<int>> children;
unordered_map<int, unordered_set<int>> lockedChildren;


bool isAncestorLocked(int num){

    int curr = num;

    while(curr != -1){
        // ancestor is locked
        if(locked[curr] != -1) return true;

        curr = parent[curr];
    }
    
    // no ancestor is locked
    return false;			
}
bool lock(int num, int user){

    // current node is already locked so not possible
    if(locked[num] != -1) return false;
    
    //if the current node have locked descendants then not possible to lock
    if(lockedChildren.find(num) != lockedChildren.end() && lockedChildren[num].size() != 0) return false;

    // check if any ancestor is locked
    if(isAncestorLocked(num)) 
        return false;
    
    // Node is not locked yet, so lock it
    locked[num] = user;
    return true;
}