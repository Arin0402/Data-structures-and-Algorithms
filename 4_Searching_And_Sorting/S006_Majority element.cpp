#include <bits/stdc++.h>
using namespace std;

// find all the elements in arrray whicH appears more than n/2 times.

// 1
// naive
// traverse array for each element and check;
// O(n^2)

// 2
// using hashing
// O(n)
// O(n)

// 3
// Moore voting algorithm
class Solution
{
public:
    int majorityElement(int a[], int size)
    {

        int cnt = 0;
        int ele = 0;

        // finding ele using moore's algo.
        for (int i = 0; i < size; i++)
        {

            if (cnt == 0)
                ele = a[i];

            if (a[i] == ele)
                cnt++;
            else
                cnt--;
        }

        // if majority element always exists, then we simply return the ele.
        // but if we it does not exist, then we have to vrify if it appears
        // more than n/2 or not.

        cnt = 0;

        // get count of ele got from moore's algo.
        for (int i = 0; i < size; i++)
        {

            if (a[i] == ele)
                cnt++;
        }

        // check
        if (cnt > size / 2)
            return ele;

        // not majority element.
        return -1;
    }
};
