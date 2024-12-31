#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// 1
// using topological sort

class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        // adjancency list
        vector<pair<int, int>> adj[N];

        for (auto vec : edges)
        {

            int first = vec[0];
            int second = vec[1];
            int weight = vec[2];

            adj[first].push_back({second, weight});
        }

        // calculate indegree
        vector<int> indegree(N, 0);

        for (int i = 0; i < N; i++)
        {
            for (auto ele : adj[i])
            {
                indegree[ele.first]++;
            }
        }

        vector<int> topo;

        // distance for each node in topo vector
        vector<int> dist(N, 1e9);

        dist[0] = 0;

        // topological sort
        queue<int> q;

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto p : adj[node])
            {

                int ele = p.first;
                int weight = p.second;

                indegree[ele]--;

                if (dist[node] + weight < dist[ele])
                {
                    dist[ele] = dist[node] + weight;
                }

                if (indegree[ele] == 0)
                    q.push(ele);
            }
        }

        // set the unreachable as -1
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

// 2
// using dijkstra's algorithm

typedef pair<int, int> iPair;

class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        // adjancency list
        vector<pair<int, int>> adj[N];

        for (auto vec : edges)
        {

            int first = vec[0];
            int second = vec[1];
            int weight = vec[2];

            adj[first].push_back({second, weight});
        }

        // min heap priority queue.
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        // distance vector.
        vector<int> dis(N, INT_MAX);

        pq.push({0, 0}); // push initial node.
        dis[0] = 0;      // make distance zero.

        while (!pq.empty())
        {

            int distance = pq.top().first; // Distance travelled to reach the node.
            int node = pq.top().second;

            pq.pop();

            for (auto p : adj[node])
            {

                int ele = p.first;
                int dist = p.second; // distance to be travelled to reach this node.

                if (distance + dist < dis[ele])
                {
                    dis[ele] = distance + dist;
                    pq.push({dis[ele], ele});
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dis[i] == INT_MAX)
                dis[i] = -1;
        }

        return dis;
    }
};
