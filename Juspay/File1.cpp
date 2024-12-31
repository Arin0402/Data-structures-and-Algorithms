#include<bits/stdc++.h>
using namespace std;

class LockingTree {

	public:

		vector<int> parent;
		vector<int> locked;
		unordered_map<int, vector<int>> children;
        unordered_map<int, unordered_set<int>> lockedChildren;
        unordered_map<int, bool> isInUse;

		LockingTree(vector<int> &parent): locked(parent.size(), -1){
			this->parent = parent;

			int n = parent.size();
			for(int i = 1; i < n; i++){
				children[parent[i]].push_back(i);
			}
		}

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

			if(locked[num] != -1) return false;

            // the node is already in use by some other thread
            if(isInUse[num] == true) return false;
            
            //if the current node have locked descendants then not possible to lock
            if(lockedChildren.find(num) != lockedChildren.end() && lockedChildren[num].size() != 0) return false;

            // update the node's status to inUse
            isInUse[num] = true;


            int curr = parent[num];
            
            vector<int> usedNodes;

			while(curr != -1){
                                
                if(isInUse[curr] || locked[curr] != -1){

                    for(auto node: usedNodes){
                        isInUse[node] = false;
                    }

                    isInUse[num] = false;
                    return false;                    
                }

                isInUse[curr] = true;
                usedNodes.push_back(curr);
				
				curr = parent[curr];
			}


            curr = parent[num];

            while(curr != -1){

                lockedChildren[curr].insert(num);
                isInUse[curr] = false;
                curr = parent[curr];
            }
						            
			// Node is not locked yet, so lock it
			locked[num] = user;
            isInUse[num] = false;

			return true;
		}

		bool unlock(int num, int user){

			// can not unlock
			if(locked[num] != user){
				return false;
			}

			locked[num] = -1;
			return true;
		}

		bool upgrade(int num, int user){
			
            // already node is locked so not possible
			if(locked[num] != -1) return false;

			// check for ancestors. if ancestor is locked then it is not possible
			if(isAncestorLocked(num)) return false;

            //if the current node have no locked descendants then not possible to upgrade
            if(lockedChildren.find(num) != lockedChildren.end() && lockedChildren[num].size() == 0) return false;

            // check for the locked children
            if (lockedChildren.find(num) != lockedChildren.end()) {
                
                for ( auto& child : lockedChildren[num]) {
                    // node is locked but locked by different user so not possible
                    if(locked[child] != -1 && locked[child] != num) return false;
                }

            }											                                
			
            // unlock the locked nodes
            for(auto& child : lockedChildren[num]) locked[child] = -1;
                            
            locked[num] = user;
            return true;		
        }
};

int main(){

	int n; // number of nodes
	int m; // children per node
	int q; // no. of queries

	cin>>n;
	cin>>m;
	cin>>q;

	// map to get the integer value of country
	unordered_map<string, int> countryCode;

	// input for countries name
	for(int i = 0; i < n; i++){
		string temp;
		cin>>temp;
		countryCode[temp] = i;
	}		


	// parent vector
	vector<int> parent(n, -1);

	// populate parent vector
	int currval = 0;

	int i = 1;
	while(i < n){

		for(int j = i; j < i + m; j++){
			parent[j] = currval;
		}

		i += m;
		currval++;
	}	
	
	LockingTree* tree = new LockingTree(parent);

	// input the queries
	for(int i = 0; i < q; i++){

		int operation;
		string countryName;
		int user;

		cin>>operation;
		cin>>countryName;
		cin>>user;
		
		// country code of the country
		int countryId = countryCode[countryName];		

		switch (operation) {
			
			case 1:
				cout<< (tree->lock( countryId, user) ? "true" : "false")<<endl;
				break;
			case 2:
				cout<< (tree->unlock( countryId, user) ? "true" : "false")<<endl;
				break;
			case 3:
				cout<< (tree->upgrade( countryId, user) ? "true" : "false")<<endl;
				break;			
		}

	}
	
}