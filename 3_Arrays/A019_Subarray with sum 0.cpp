#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// 1
// naive approach
// traverse through all the subarrays and find the sum.
// O(N^3);

// 2
// Initialise a variable sum.
// traverse through the array and keep adding element to the sum.
// insert this sum into set.
// if the sum is already present in the set , then it means we have already acheieved that sum and rest of the elements
// added after obtaining that sum results into zero.
// Ex-  4 2 -3 1 5 .

// step 1 , sum = 4, set = 4
// step 2 , sum = 6, set = 4 6
// step 3 , sum = 3, set = 4 6 3
// step 4 , sum = 4, set = 4 6 3
// Here we got sum 4 again so sum of 2 -3 1 is resulting into 0 that's why we are again obtaining the same sum

// TC - O(n);

class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.

    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> st;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            sum += arr[i];

            if (sum == 0 || st.find(sum) != st.end())
                return true;
            st.insert(sum);
        }

        return false;
    }
};

