#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=wiDLcGxhh80

// 1
// simple operation is to merge all the elements to form single element , this would form a single element
// which would be palindrome.
// Takes n-1 operations.

// 2
// Two pointer

int findMinOps(int arr[], int n)
{
	int ans = 0; // Initialize result

	// Start from two corners
	for (int i = 0, j = n - 1; i <= j;)
	{
		// If corner elements are same,
		// problem reduces arr[i+1..j-1]
		if (arr[i] == arr[j])
		{
			i++;
			j--;
		}

		// If left element is greater, then
		// we merge right two elements
		else if (arr[i] > arr[j])
		{
			// need to merge from tail.
			j--;
			arr[j] += arr[j + 1];
			ans++;
		}

		// Else we merge left two elements
		else
		{
			i++;
			arr[i] += arr[i - 1];
			ans++;
		}
	}

	return ans;
}
