#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/topological-sort/1

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

// Topological sort is only valid in DAG.
//  DFS Solution.
class Solution
{
public:
    void dfs(int node, vector<int> &vis, stack<int> &s, vector<int> adj[])
    {

        vis[node] = 1;

        for (auto ele : adj[node])
        {

            if (vis[ele] == 0)
                dfs(ele, vis, s, adj);
        }

        s.push(node); // push into the stack as the dfs is completed.
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {

        stack<int> s; // to store the elements whose dfs is complete.
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (vis[i] == 0)
                dfs(i, vis, s, adj);
        }

        // answer part.
        vector<int> ans;

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};