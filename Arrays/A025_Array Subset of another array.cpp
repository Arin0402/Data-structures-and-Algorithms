#include <bits/stdc++.h>
using namespace std;

// find if one array is subset of another or not.
// Note - duplicates elements are allowed.

// 1
// two for loops

// 2
// sort both the arrays
// use two pointers and comapare.
// O(nlogn) + O(n).

// 3
// use map;
// TC - O(n + m)
// SC - O(n)



string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int, int> mp;
    
    // count frequency of each element of array1.
    for(int i = 0 ; i < n ; i++) mp[a1[i]] += 1;


    for(int i =0; i < m ; i++){
        
        // element present, so decrease it's count. (Due to duplicate elements)
        if(mp[a2[i]] > 0){
            mp[a2[i]] -= 1;
            
        }
        else{
            return "No";           
        }
        
    }
    
    return "Yes";
}

