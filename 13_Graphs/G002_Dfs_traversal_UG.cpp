#include <bits/stdc++.h>
using namespace std;

// TC - O (V + E); (E - edges)
class Solution
{
    void Helper(int ind, vector<int> adj[], vector<int> &ans, vector<int> &visited)
    {

        ans.push_back(ind);
        visited[ind] = true;

        for (auto ele : adj[ind])
        {

            if (visited[ele] == false)
            {
                Helper(ele, adj, ans, visited);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> ans;
        vector<int> visited(V, false);

        Helper(0, adj, ans, visited);

        return ans;
    }
};
