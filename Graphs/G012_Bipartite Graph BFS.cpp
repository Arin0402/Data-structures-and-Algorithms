#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs(int start, vector<int> &color, vector<int> adj[], int V)
    {

        queue<int> q;
        q.push(start);

        color[start] = 0; // colour the starting node with colour 0

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            for (auto ele : adj[node])
            {

                // if the adjacent node is yet not colored
                // we will give the opposite color of the node
                if (color[ele] == -1)
                {
                    color[ele] = !color[node];
                    q.push(ele);
                }

                // if the adjacent node having the same color
                // someone did color it on some other path
                else if (color[ele] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {

        vector<int> color(V, -1); // denotes the colour.

        for (int i = 0; i < V; i++)
        { // for multiple components

            if (color[i] == -1)
            {

                if (bfs(i, color, adj, V) == false)
                    return false;
            }
        }

        return true;
    }
};
