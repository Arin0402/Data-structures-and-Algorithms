#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

// 1
// check bit one by one
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int count = 0;
        
        while(a != 0 || b != 0){
            
            if((a&1) != (b&1)) count++;
            
            a = a>>1;
            b = b>>1;
        }
        
        return count;
    }
};

// 2
// find xor of both the numbers and count the njumber of 1's in the xor.
// number of 1's can be found by removing the right most 1's bit one by one untill the xor reduces to zero.
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int count = 0;
        
        int Xor = a^b;
        
        // removing the right most 1's bit one by one untill the xor reduces to zero.
        while(Xor){
            count++;
            
            Xor = Xor&(Xor-1);
        }
        
        return count;
    }
};

