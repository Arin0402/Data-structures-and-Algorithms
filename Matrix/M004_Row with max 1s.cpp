#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// count for every row, find max

// 2
// using binary search
// count the number of 1 for evry row using binary search.
class Solution
{
public:
	// binary search to find the number of i's in a row.
	int binary(vector<int> &arr)
	{

		int n = arr.size();

		int low = 0;
		int high = n - 1;

		while (low <= high)
		{

			int mid = low + (high - low) / 2;

			if (arr[mid] == 1)
				high = mid - 1;
			else
				low = mid + 1;
		}

		// number of 1's.
		return n - low;
	}

	int rowWithMax1s(vector<vector<int>> arr, int n, int m)
	{

		int Max = 0, ind = -1;

		for (int i = 0; i < arr.size(); i++)
		{

			int cnt = binary(arr[i]);
			if (cnt > Max)
			{
				Max = cnt;
				ind = i;
			}
		}

		return ind;
	}
};

// 3
// O(m+n)
class Solution
{
public:
	int rowWithMax1s(vector<vector<int>> arr, int n, int m)
	{

		int j = m - 1; // start from the last column of first row.
		int ind = -1;

		// interate for number of rows.
		for (int i = 0; i < n; i++)
		{

			bool flag = false;

			// starting from back , we check if there are 1 available from previous index onwards.
			while (j >= 0 && arr[i][j] == 1)
			{

				j--;
				flag = true; // got more 1's.
			}

			if (flag)
				ind = i;
		}

		return ind;
	}
};