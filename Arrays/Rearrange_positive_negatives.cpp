#include <iostream>
using namespace std;

// Swap Function.
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Using Dutch National Flag Algorithm.
void reArrange(int arr[], int n)
{
	int low = 0, high = n - 1;
	while (low < high)
	{
		if (arr[low] < 0)
		{
			low++;
		}
		else if (arr[high] > 0)
		{
			high--;
		}
		else
		{
			swap(arr[low], arr[high]);
		}
	}
}
void displayArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	// Data
	int arr[] = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	reArrange(arr, n);
	displayArray(arr, n);
	return 0;
}
