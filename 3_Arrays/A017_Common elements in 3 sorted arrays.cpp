#include <bits/stdc++.h>
using namespace std;

// 1
// Find intersection of two arrays, store it in temp array,
// the find the intersection of the third array with the temp array.
// TC - O(n1 + n2 + n3)
// This requires extra space and two loops.

// 2
// using map data structure.
// TC - O(n1 + n2 + n3)
// requires extra space.
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {

        unordered_map<int, int> mp;

        // insert elements of first array.
        for (int i = 0; i < n1; i++)
        {
            if (mp[A[i]] == 0)
                mp[A[i]] += 1;
        }

        // increment counter only if the count if 1.
        for (int i = 0; i < n2; i++)
        {
            if (mp[B[i]] == 1)
                mp[B[i]] += 1;
        }

        // increment counter only if the count if 2.
        for (int i = 0; i < n3; i++)
        {

            if (mp[C[i]] == 2)
                mp[C[i]] += 1;
        }

        vector<int> ans;

        for (int i = 0; i < n1; i++)
        {

            if (mp[A[i]] == 3)
            { // if count is three
                ans.push_back(A[i]);
                mp[A[i]] = 0; // avoid duplicates.
            }
        }

        return ans;
    }
};

// 3
// using single loop
// TC - same as above
// no extra space.
class Solution1
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {

        int i = 0, j = 0, k = 0;

        vector<int> ans;

        while (i < n1 && j < n2 && k < n3)
        {

            if (A[i] == B[j] && B[j] == C[k])
            {
                ans.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
                i++;
            else if (B[j] < C[k])
                j++;
            else
                k++;

            // avoid duplicates.
            while (i - 1 >= 0 && A[i] == A[i - 1])
                i++;
            while (j - 1 >= 0 && B[j] == B[j - 1])
                j++;
            while (k - 1 >= 0 && C[k] == C[k - 1])
                k++;
        }

        return ans;
    }
};

// 4
// using Binary secarch (easy but time consuming).
// iterate over first array.
// find if each element exists in both the elements or not.
// O(n1(log(n2*n3))