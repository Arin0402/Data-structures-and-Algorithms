#include <iostream>
using namespace std;

int main()
{

	while (true)
	{

		int n;

		cin >> n;

		if (n == 0)
			break;

		// input first array.
		int arr1[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr1[i];
		}

		int m;
		cin >> m;

		int arr2[m];

		// input second array.
		for (int i = 0; i < m; i++)
		{
			cin >> arr2[i];
		}

		// pointers.
		int p1 = 0, p2 = 0;

		// individual sums.
		int sum1 = 0, sum2 = 0;

		int maxi = 0;

		while (p1 < n && p2 < m)
		{

			// first array element is smaller, add it to sum1.
			if (arr1[p1] < arr2[p2])
			{
				sum1 += arr1[p1++];
			}
			// second array element is smaller, add it to sum2.
			else if (arr2[p2] < arr1[p1])
			{
				sum2 += arr2[p2++];
			}
			// found common element.
			else
			{

				// add the maximum of the two sum to the answer + the bridge element.
				maxi += max(sum1, sum2) + arr1[p1];

				p1++;
				p2++;

				// make the sum zero as we have to calculate sum for the elements after the bridge is found.
				sum1 = 0;
				sum2 = 0;
			}
		}

		while (p1 < n)
		{
			sum1 += arr1[p1++];
		}

		while (p2 < m)
		{
			sum2 += arr2[p2++];
		}

		// leftover sum.
		maxi += max(sum1, sum2);

		cout << maxi << endl;
	}

	return 0;
}