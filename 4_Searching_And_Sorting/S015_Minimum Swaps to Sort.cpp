#include <bits/stdc++.h>
using namespace std;

// 1
// O(n^2)
class Solution
{
public:
	// we will convert sorted array back to the original array.
	// this will help as we will know where we have to put the
	// element( when converting from sorted to unsorted ).

	int minSwaps(vector<int> &nums)
	{

		int n = nums.size();

		vector<pair<int, int>> sorted(n);

		// make pair with element and index.
		for (int i = 0; i < n; i++)
		{
			sorted[i] = make_pair(nums[i], i);
		}

		// sort the array wiht index.
		sort(sorted.begin(), sorted.end());

		int cnt = 0;

		int i = 0;

		while (i < n)
		{

			auto p = sorted[i];

			// element is present at same position in sorted and unsorted array.
			if (i == p.second)
				i++;
			else
			{

				swap(sorted[i], sorted[p.second]);
				cnt++;
			}
		}

		return cnt;
	}
};

// 2
// O(nlogn)
// map method
// bit complex.