#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// 1
// sorting and checking.

// 2
// using map
// requires extra space.

// 3
// using summation and square.
// Method 7 in editorial(gfg).
// only watch this part.
// https://www.youtube.com/watch?v=5nMGY4VUoRY&t=151s
// O(n)

// 4
// place every element in it's correct position.
// then easily find out the missing and repeating.
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {

        int i = 0;

        // place every element to it's correct position.
        while (i < n)
        {

            if (arr[i] == arr[arr[i] - 1])
                i++;
            else
                swap(arr[i], arr[arr[i] - 1]);
        }

        // answer array.
        int *ans = new int[2];

        int missing = -1;
        int repeating = -1;

        // check by iterating.
        for (int i = 0; i < n; i++)
        {

            if (arr[i] != i + 1)
            { // element does not match with index + 1.

                repeating = arr[i];
                missing = i + 1;
                break;
            }
        }

        ans[0] = repeating;
        ans[1] = missing;

        return ans;
    }
};
