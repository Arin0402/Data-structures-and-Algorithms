#include <bits/stdc++.h>
using namespace std;

// 1
// naive,  try all triplets
// O(N^3)

// 2
// O(n^2)
class Solution
{

public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
		sort(arr, arr + n);

		int cnt = 0;

		for (int i = 0; i < n - 2; i++)
		{

			int l = i + 1;
			int r = n - 1;

			while (l < r)
			{

				if (arr[i] + arr[l] + arr[r] >= sum)
				{

					r--;
				}
				else
				{
					// ex - -2, 0, 1 2 3 4 , sum = 3

					// sum of {-2, 0, 4} is less than 3
					// so sum of {-2, 0, 1}, {-2, 0, 2}, {-2, 0, 3} will also be less than 3.

					cnt += (r - l);
					l++;
				}
			}
		}

		return cnt;
	}
};