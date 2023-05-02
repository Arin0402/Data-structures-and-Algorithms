#include <bits/stdc++.h>
using namespace std;

// refer this if confusion.
// https://www.youtube.com/watch?v=CsGP_s_3GWg
bool dfs(int node, int time, int parent, int V, vector<int> adj[], int c, int d, vector<bool> &vis, vector<int> &first, vector<int> &last)
{

    vis[node] = true;
    first[node] = time;
    last[node] = time;

    time += 1;

    for (auto ele : adj[node])
    {

        if (ele == parent)
            continue;

        if (vis[ele] == false)
        {

            if (dfs(ele, time, node, V, adj, c, d, vis, first, last))
                return true;

            if (last[ele] > first[node])
            {

                // found bridge between the nodes c and d.
                // We will not find further bridges.
                if ((ele == c && node == d) || (ele == d && node == c))
                    return true;
            }
            else
            {
                last[node] = min(last[node], last[ele]);
            }
        }
        else
            last[node] = min(last[node], first[ele]);
    }

    return false;
}

int isBridge(int V, vector<int> adj[], int c, int d)
{

    vector<bool> vis(V, false);
    vector<int> first(V, -1);
    vector<int> last(V, -1);

    for (int i = 0; i < V; i++)
    {

        if (vis[i] == false)
        {
            if (dfs(i, 0, -1, V, adj, c, d, vis, first, last))
                return true;
        }
    }

    return false;
}