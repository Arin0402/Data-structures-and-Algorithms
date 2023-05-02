#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=

// 1
// using hashing

// 2
// using math property
// video

// 3
// using xor property
// O(5N)
// O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        int xor1 = 0; // xor of array elemetns
        int xor2 = 0; // xor of elemetns 1 to n
        
        for(int i = 0; i < n; i++){
            xor1 ^= arr[i];
        }
        
        for(int i = 0; i < n; i++){
            xor2 ^= (i + 1);
        }
        
        // xor of repeating and missing element.
        int xor3 =xor1^xor2;
        
        // rightmost set bit of xor3;
        int rightMost = xor3 & ( ~ (xor3 - 1)) ;
        
        // ele1 is the xor of elements which have rightMost set bit as set.
        // ele2 vice versa
        
        int ele1 = 0, ele2 = 0;
        
        // for array elemetns
        for(int i = 0; i < n; i++){
            
            if(arr[i] & rightMost){
                ele1 ^= arr[i];
            }
            else ele2 ^= arr[i];
        }
        
        // for elemets 1 to n
        for(int i = 0; i < n; i++){
            
            if((i + 1) & rightMost){
                ele1 ^= (i + 1);
            }
            else ele2 ^= (i + 1);
        }
        
        
        // Now we have to elements, but we don't know which one is which
        // so check
        
        // check if ele1 is present.
        bool isPresent = false;
        
        for(int i = 0; i < n; i++){
            
            if(arr[i] == ele1){
                isPresent = true;
                break;
            }
        }
        
        
        int* ans = new int[2];
        
        // if ele1 is present, then it is the repeated element.
        if(isPresent == true){
            ans[0] = ele1;
            ans[1] = ele2;
            return ans;
        }
        else{
            ans[0] = ele2;
            ans[1] = ele1;
            return ans;
        }
        
        
    }
};