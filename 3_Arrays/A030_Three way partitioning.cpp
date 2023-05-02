#include <bits/stdc++.h>
using namespace std;

// 1  
// sort the whole array.
// O(nlogn)

// 2
// simple Dutch national flag algo.
// same as 0,1,2 sort.
class Solution{   
public:    
    
    void swap(int *a, int *b){
        
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        
        int n = array.size();
        
        int l = 0;
        int mid  = 0;
        int h = n-1;
        
        while( mid <= h ){
            
            if(array[mid] < a){
                swap(&array[l], &array[mid]);
                l++;
                mid++;
            }
            else if(array[mid] > b){
                swap(&array[mid], &array[h]);
                h--;
            }
            else mid++;
            
        }
        
    }
};
