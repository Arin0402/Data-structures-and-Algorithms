#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

// Only 2 possibilities are there. First to have a sequence "010101..." and second to have a sequence "1010101...".
// Calculate the flips required to convert the string into both and return the minimum.

int minFlips (string S)
{
    int ans1 = 0;
    int ans2 = 0;
    
    // 010101
    for(int i = 0; i < S.size(); i++){
        
        if(i%2 == 0){
            if(S[i] == '1') ans1++;
        }
        else{
            if(S[i] == '0') ans1++;
        }
        
    }
    
    // 10101
    for(int i = 0; i < S.size(); i++){
        
        if(i%2 == 0){
            if(S[i] == '0') ans2++;
        }
        else{
            if(S[i] == '1') ans2++;
        }
        
    }
    
    return min(ans1, ans2);
}