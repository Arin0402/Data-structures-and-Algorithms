#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

// 1
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	   
	   if(m == 0 || m == 1) return m;
	   
	   int low = 1;
	   int high = m;
	   
	   while(low <= high){
	       
	       int mid = low + (high -low)/2;
	       
	       if( pow(mid, n) == m ) return mid;
	       else if(pow(mid, n) < m) {
	           low = mid + 1;
	       }
	       else high = mid - 1;
	       
	   }
	   
	    return -1;
	}  
};