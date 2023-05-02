#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// 1
// O(n)

class Solution {
public:

    // for valid cases
    // 1. if array is rotated and sorted, then first element should be >= last element
    // 2. if not rotated then it should be linearly sorted.
    bool check(vector<int>& arr) {
        
        int n = arr.size();

        // case 1
        // first element is >= last element

        if(arr[0] >= arr[n-1]){

            bool flag = false;

            for(int i = 0; i < n-1; i++){
                
                if(arr[i] > arr[i+1]){
                    if(flag == false) flag = true;
                    else return false;
                }
            }

        } 

        // case 2
        // first element is <= last element
        else {

            for(int i = 0; i < n-1; i++){
                if(arr[i] > arr[i+1]){
                    return false;
                }
            }
        }

        return true;
    }
};