#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// 1
// my solution
// O(r-l)
// O(1)
class Solution{
    public:
    
    int setSetBit(int x, int y, int l, int r){
        
        // 0 based.
        l--;
        r--;
        
        // left shift y by l and then check if rightmost bit is 1 ot not.
        y = y>>l;
        
        // to keep the track of range.
        int ind = l;
        
        // this is the mask which will lie under the x.
        int temp = 1<<l;
        
        while(ind <= r){
            
            // if the rightmost bit if y is one then ..
            if((y&1) == 1){
                x = x|temp;
            }
            
            ind++;
            // right shift the mask by one.
            temp = temp<<1;
            
            // left shit the y by one.
            y = y>>1;
        }
        
        return x;
        
    }
};

// 2
// https://www.youtube.com/watch?v=v7pUZw-ZOYU
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        
        long long int mask = 1;
        
        mask = (mask<<(r - l + 1));
        
        mask = mask - 1;
        
        mask = (mask<<(l-1));
        
        mask = (mask&y);
        
        x = (x|mask);
        return x;
        
    }
};