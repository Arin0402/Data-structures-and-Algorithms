#include <bits/stdc++.h>
using namespace std;

// https://youtube.com/watch?v=0vVofAhAYjc
// easy
// TC - O(n)*O(E);

// Helps to detect negative cycles
// Works only with Directed graphs
// If there is undirected graph then

class Solution
{
public:
	
	int isNegativeWeightCycle(int n, vector<vector<int>> edges)
	{

		int INF = 1000000;

		vector<int> dis(n, INF);
		dis[0] = 0;

		// relax all the edges n-1 times.
		for (int i = 0; i < n - 1; i++)
		{

			for (auto edge : edges)
			{

				int first = edge[0];
				int second = edge[1];
				int weight = edge[2];

				if (dis[first] + weight < dis[second])
				{

					dis[second] = dis[first] + weight;
				}
			}
		}

		int flag = 0;

		// relax one more time.
		// if distance can be reduced then cycle is present.
		for (auto edge : edges)
		{

			int first = edge[0];
			int second = edge[1];
			int weight = edge[2];

			if (dis[first] + weight < dis[second])
			{

				flag = 1;
				break;
			}
		}

		return flag;
	}
};