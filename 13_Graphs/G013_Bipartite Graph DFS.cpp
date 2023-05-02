#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, vector<int> &color, vector<int> adj[])
    {

        for (auto ele : adj[node])
        {

            // next node is not coloured yet.
            if (color[ele] == -1)
            {
                color[ele] = !color[node];

                if (dfs(ele, color, adj) == false)
                    return false;
            }
            // next node is already coloured with the same colour.
            else if (color[ele] == color[node])
            {
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

                color[i] = 0;
                if (dfs(i, color, adj) == false)
                    return false;
            }
        }

        return true;
    }
};