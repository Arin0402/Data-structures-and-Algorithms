#include <bits/stdc++.h>
using namespace std;

// Solution 1;
// First compare starting two elements. - number of comparisons  = 1.
// then for(int i = 2 ; i < n; i++) { - number of comparisons = n-2.
//      compare each element.
// }
// In this method, the total number of comparisons is 1 + 2(n-2) in the worst case and 1 + n – 2 in the best case.

// SOlution 2;

struct Pair
{
    long long int max;
    long long int min;
};

pair<long long, long long> getMinMax(long long arr[], int n)
{

    Pair minmax; // Directly use pair also.
    int i;

    // if n is even.
    if (n % 2 == 0)
    { // this counts for 1 comparison.

        if (arr[0] > arr[1])
        {

            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {

            minmax.max = arr[1];
            minmax.min = arr[0];
        }

        i = 2;
    }
    else
    { // n is odd.

        minmax.max = arr[0];
        minmax.min = arr[0];

        i = 1;
    }

    // for every i , there are 3 comparisions.
    // for even,  number of comparisons 1 + 3*(n-2)/2 = 3n/2 -2
    // for odd ,  number of comparisons  3*(n-1)/2
    while (i < n - 1)
    {

        if (arr[i] > arr[i + 1])
        {

            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }
            if (arr[i + 1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > minmax.max)
            {
                minmax.max = arr[i + 1];
            }
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
        }

        i += 2; // loop will run for half of the elements.
    }

    pair<long long, long long> ans;

    ans.first = minmax.min;
    ans.second = minmax.max;

    return ans;
}