#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

// 1
// naive
// search for every element in each row

// 2
// using binary search

// 3
// map
// O(m*n)

#define M 4
#define N 5

// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;

    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;

    // traverse the matrix
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
                // we increment count of the element
                // in map by 1
                mp[mat[i][j]] = i + 1;

                // If this is last row
                if (i == M - 1 && mp[mat[i][j]] == M)
                    cout << mat[i][j] << " ";
            }
        }
    }
}