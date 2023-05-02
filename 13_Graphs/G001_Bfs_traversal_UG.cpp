#include <bits/stdc++.h>
using namespace std;

// TC - O (N + 2*E); (E - edges)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{

    queue<int> q;

    q.push(0);
    vector<int> ans;

    vector<bool> visited(V, false);

    visited[0] = true;

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int i : adj[node])
        {

            if (visited[i] == false)
            {

                q.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}
