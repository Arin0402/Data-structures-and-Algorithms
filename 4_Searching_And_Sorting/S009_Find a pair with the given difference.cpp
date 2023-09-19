#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

// 1
// two for loops
// O(n^2)

// 2
// sort the array
// pick elements from start and do binary search on rest.
// O(nlogn)

// 3
// using two pointers.
// sort the array.
// take two pointers i = 0, j = 1;
// traverse while i < n && j < n;

bool findPair(int arr[], int size, int n)
{

    sort(arr, arr + size);

    int i = 0, j = 1;

    while (i < size && j < size)
    {

        // found the difference.
        if (i != j && (arr[i] - arr[j] == n || arr[j] - arr[i] == n))
        {
            return true;
        }
        // difference is less so increment right pointer.
        else if (arr[j] - arr[i] < n)
            j++;
        // difference is large so increment left pointer.
        else
            i++;
    }

    return false;
}

// 4
// using set
// O(n)

bool findPair(int arr[], int size, int n)
{

    unordered_set<int> st;

    for (int i = 0; i < size; i++)
    {

        if (st.find(arr[i] - n) != st.end())
        {

            return true;
        }

        if (st.find(arr[i] + n) != st.end())
        {

            return true;
        }

        st.insert(arr[i]);
    }

    return false;
}
