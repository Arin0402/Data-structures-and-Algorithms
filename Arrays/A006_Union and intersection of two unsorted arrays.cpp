#include <bits/stdc++.h>
using namespace std;

// using unordered_set
// set operation O(1);
// total TC = O(m+n);

// using unordered_map;
// same

// if asked in O(1) space then.
// Method 1. sorting and compairing.
// Method 2. sorting smaller array, doing binary search on smaller array for the elements of larger array. This method also works only for distinct elements in input arrays.

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {

        unordered_set<int> st;

        for (int i = 0; i < n; i++)
            st.insert(a[i]);
        for (int i = 0; i < m; i++)
            st.insert(b[i]);

        return st.size();
    }
};