#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// BFS solution.

// TC - O (N + 2*E) + O(N).
class Solution{
public:
    bool detect(int src, vector<int> adj[], vector<bool> &vis) // O (N + 2*E)
    {

        queue<pair<int, int>> q;

        q.push({src, -1}); // push parent as -1 intially.
        vis[src] = true;

        while (!q.empty())
        {

            auto currNode = q.front().first;
            int parentNode_value = q.front().second;
            q.pop();
            
            for(auto ele : adj[currNode]){
                
                if(vis[ele] == false){
                    
                    q.push({ele, currNode}); // make currNode as parent.
                    vis[ele]  = true;
                }
                else if( parentNode_value != ele){ // if the ele is visited and the ele is not equal to the parentNode_value of the currNode, then it must be visited earlier.
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {

        vector<bool> vis(V, 0);

        for (int i = 0; i < V; i++) // O(N)
        {                           // avoid repettion in graph with broken components.

            if (vis[i] == false)
            {

                if (detect(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};