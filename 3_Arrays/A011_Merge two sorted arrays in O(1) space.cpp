#include <bits/stdc++.h>
using namespace std;

// 1
// using extra space

// 2
// using insertion sort type algo.
// 2 minutes onwards.
// https://www.youtube.com/watch?v=hVl2b3bLzBw
// O(n*m)

// 3
// O((n+m)log(n+m))
// Gap algo.
class Solution{
    public:
        //Function to merge the arrays.
        
        void swap(long long int *a,long long int* b){
            int t = *a;
            *a = *b;
            *b = t;
        }
        
        // calculates the gap.
        int nextGap(int gap)
        {
            if (gap <= 1)
                return 0;
            return (gap / 2) + (gap % 2);
        }
    
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int total = n + m;
            int wind = nextGap(total);
            
            while(wind > 0){
                
                int l = 0;
                int r = wind;
                
                while(r < total){
                    
                    if(l < n && r < n){
                        
                        if(arr1[l] > arr1[r]) swap(&arr1[l], &arr1[r]);
                    }
                    else if( l < n && r >= n){
                         
                        if(arr1[l] > arr2[r-n]) swap(&arr1[l], &arr2[r-n]);
                        
                    }
                    else if(l >= n && r >= n ){
                        
                        if(arr2[l-n] > arr2[r-n]) swap(&arr2[l-n], &arr2[r-n]);
                        
                    }
                    
                    l++;
                    r++;
                    
                }
                
                wind  = nextGap(wind);
                
            }
        } 
};
