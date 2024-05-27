#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/arithmetic-number2815/1
// find missing number in an arithmetic progression.

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {

        // A  - first term
        // B - number to be checked
        // C - difference.

        // Note - -16 % 4  is equal to 0

        if (C == 0)
            return (B == A);

        return ((B - A) % C == 0 && (B - A) / C >= 0);
    }
};

// https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{   
public:
    int findMissing(int arr[], int n) {
        
        int diff = (arr[n-1] - arr[0])/n;
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            int elementShouldBe = arr[0] + mid*diff;
            
            if(elementShouldBe == arr[mid]) low = mid + 1;
            else high = mid - 1;
            
        }
        
        return arr[high] + diff;
    }
};
