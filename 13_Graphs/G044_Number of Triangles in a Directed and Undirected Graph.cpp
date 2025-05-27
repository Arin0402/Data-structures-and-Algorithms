#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.o rg/number-of-triangles-in-directed-and-undirected-graphs/

class Solution
{
    // read article.
public:
    int numberOfTriangles(vector<vector<int>> &graph, int n)
    {

        int count = 0;

        // this one is directd graph.
        // try every triplet of nodes and if edges exist then increment.

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {

                    if (i != j && i != k && j != k)
                    {
                        if (graph[i][j] && graph[j][k] && graph[k][i])
                            count++;
                    }
                }
            }
        }
        // For the same triangle the counter will be incrementd three times so divide by three.
        return count / 3;
    }
};