#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

// TC -> https://www.youtube.com/watch?v=3dINsjyfooY&t=488s

// implementation using priority queue.
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.

    // TC  O(E* logV)
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // min heap priority queue.
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        // distance vector.
        vector<int> dis(V, INT_MAX);

        pq.push({0, S}); // push initial node.
        dis[S] = 0;      // make distance zero.

        while (!pq.empty())
        {

            int distance = pq.top().first; // Distance travelled to reach the node.
            int node = pq.top().second;

            pq.pop();

            for (auto vec : adj[node])
            {

                int ele = vec[0];
                int dist = vec[1]; // distance to be travelled to reach this node.

                if (distance + dist < dis[ele])
                {
                    dis[ele] = distance + dist;
                    pq.push({dis[ele], ele});
                }
            }
        }

        return dis;
    }

    // Note - we can use simple queue also , but using that will increase the insertitions in the queue
    // as we may take largest distance node first and then update the rest nodes.
    // this will increase unnecessary insertitions in the queue.
    // TC will be O(V^2)
};

// implementation using set.
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    set<pair<int, int>> st; // {distance, node}

    // distance vector.
    vector<int> dis(V, 1e9);

    st.insert({0, S});

    dis[S] = 0; // make distance zero.

    while (!st.empty())
    {

        auto it = *(st.begin());
        int distance = it.first; // Distance travelled to reach the node.
        int node = it.second;

        st.erase(it);

        for (auto vec : adj[node])
        {

            int ele = vec[0];
            int dist = vec[1]; // distance to be travelled to reach this node.

            if (distance + dist < dis[ele])
            {

                // if the node already exists with larger distance, then there is no point
                // in storing it as we have found smaller distance.
                // so set saves iteration again.
                if (dis[ele] != 1e9)
                {
                    st.erase({dis[ele], ele});
                }

                dis[ele] = distance + dist;
                st.insert({dis[ele], ele});
            }
        }
    }

    return dis;
}