#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

// 1
// using insertion sort to sort the runnig stream of elements and find the median
// O(n^2)

// 2
// using two heaps
// O(nlogn)

class Solution
{
    public:
    
    // max heap
    priority_queue<int> maxhp; // left part
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> minhp; // right part
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        
        int n = maxhp.size();
        int m = minhp.size();
        
        int left, right;
        
        // both are empty.
        
        if(n == 0 && m == 0){
            maxhp.push(x);
        }
        
        // maxhp is empty
        else if(n == 0){
            
            right = minhp.top();
            
            if(x < right ) maxhp.push(x); // n becomes 1
            
            // else shift one elemnt into maxhp.
            else{
                minhp.pop();
                maxhp.push(right);
                minhp.push(x);
            }
        }
        
        // minhp is empty
        else if( m == 0){
            
            left = maxhp.top();  
            
            if(x > left) minhp.push(x); // m becomes 1
            
            // else shift one elemnt into minhp.
            else{
                maxhp.pop();
                minhp.push(left);
                maxhp.push(x);
            }
            
        }
        
        // both are same;
        else if(n == m){
            
            left = maxhp.top();
            right = minhp.top();
            
            if( x <= left) maxhp.push(x); // n+1 m
            else minhp.push(x); // n m+1
        }
        
        // n > m
        else if(n > m){
            
            left = maxhp.top();
            right = minhp.top();
            
            if(x > left) minhp.push(x); // n and m become same.
            
            // else shift one elemnt into minhp.
            else{ 
                maxhp.pop();
                minhp.push(left);
                maxhp.push(x); // n and m become same.
            }
        }
        else{
            
            left = maxhp.top();
            right = minhp.top();
            
            if(x < right) maxhp.push(x); // n and m become same.
            
            // else shift one elemnt into maxhp.
            else{
                minhp.pop();
                maxhp.push(right);
                minhp.push(x); // n and m become same.
            }
            
        }
            
    
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        
        int n = maxhp.size();
        int m = minhp.size();
        
        int left = 0, right = 0;
        
        if(n != 0) left = maxhp.top();
        if(m != 0) right = minhp.top();
        
        
        if(n == m) return (left + right)/2.0;
        else if( n > m) return left;
        else return right;
        
    }
};
