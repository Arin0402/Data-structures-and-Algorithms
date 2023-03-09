#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

// https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1

// 1
// !-------------------NOTE-------------------!
// to find the element in the nth row and cth column
// formula is  (r-1)C(c-1)  (this is nCr).

// 2
// to find the nth row
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        
        if(n == 1) return {1};
        
        vector<ll> first;
        first.push_back(1);
        
        for(int i = 1; i < n; i++){
            
            vector<ll> second;
                
            int sizeOfFirst = first.size();
            second.push_back(1);
            
            for(int j = 1; j < sizeOfFirst; j++){
                
                int sum = (first[j]%1000000007 + first[j-1]%1000000007 + 1000000007)%1000000007;
                second.push_back(sum);
            }
            
            second.push_back(1);
            
            first = second;
        }
        
        return first;
    }
};
