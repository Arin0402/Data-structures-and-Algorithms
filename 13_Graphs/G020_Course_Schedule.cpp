#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/course-schedule/1

// same as prerequistes tasks. just return the order of tasks i.e topo sort.
class Solution
{
public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
    {

        // create adjacency list.
        vector<int> adj[V];

        for (auto it : prerequisites)
        {

            adj[it[1]].push_back(it[0]);
        }

        // calculate indegree of all the nodes.
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {

            for (auto ele : adj[i])
            {
                indegree[ele]++;
            }
        }

        // Push all the node with indegree zero.
        // elements with indegree zero will be the first elements.
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto ele : adj[node])
            {

                indegree[ele]--; // subtract the indegrees for the adjacent nodes of the current node.

                if (indegree[ele] == 0)
                    q.push(ele);
            }
        }

        for (int i = 0; i < V; i++)
            cout << topo[i] << " ";
        cout << endl;
        return topo;
    }
};
