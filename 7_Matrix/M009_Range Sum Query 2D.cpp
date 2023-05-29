#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

#define ll long long int

class NumMatrix {
public:

    vector<vector<ll>> pref;
    
    // creating 2d prefix matrix
    NumMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        // 1 based indexing
        pref = vector<vector<ll>>(n+1, vector<ll>(m+1, 0));

        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= m; j++){
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // for 1 based indexing
        row1++;
        col1++;
        row2++;
        col2++;

        return pref[row2][col2] - pref[row2][col1-1] - pref[row1- 1][col2] + pref[row1-1][col1-1];


    }
};  