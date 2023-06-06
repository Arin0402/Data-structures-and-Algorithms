#include <bits/stdc++.h>
using namespace std;

// 1
// O(N^2)
// two for loops

// 2
// using tow pointers
// O(N)


int countSubarrays(int arr[], int n, int k)
{
	int start = 0, end = 0, count = 0, sum = arr[0];

	while (start < n && end < n) {

		// If sum is less than k,
		// move end by one position.
		// Update count and sum
		// accordingly.
		if (sum < k) {
			end++;

			if (end >= start)
				count += end - start;

			// For last element,
			// end may become n
			if (end < n)
				sum += arr[end];
		}

		// If sum is greater than or
		// equal to k, subtract
		// arr[start] from sum and
		// decrease sliding window by
		// moving start by one position
		else {
			sum -= arr[start];
			start++;
		}
	}

	return count;
}
