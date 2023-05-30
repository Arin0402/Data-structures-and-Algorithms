#include <bits/stdc++.h>
using namespace std;

// An engineer is constructing a new building and is given certain working conditions to follow during the construction.
 
// The workers and capacities that participate in the construction are listed in an array of integers.
// The capacity of each of the workers is listed in the array as an integer.
// The construction needs to conform to the following rules:
// There must be a total of 3 workers chosen from the capacity array, referred to as a triplet
// At least 2 of the chosen workers must be adjacent in the array
// The capacity of each of the chosen workers, when multiplied together, must equal a given desiredCapacity


// Solution

// we have to make pair as two elements must be adjacent
// there can be n-1 pairs for n array

// run a for loop and go for each each adjacent pair
// then we just have to find the third element in the remaining array.

// we have to count the number of occurence of third element in the remaining array on both the sides
// this will lead to duplicacy but the duplicates triplets would be removed later

// tripltes in which all the three elements are adjacent cause the duplicacy

// for example

//            1 3 5 3 5
// pairs ->   (0 1 2)
// pairs ->   (0 1 4)
// pairs ->   (0 1 2)
// pairs ->   (0 2 3)
// pairs ->   (0 3 4)

// to remove the duplicates, count the adjacent triplets which have multiplication result = k
// remove the count from the final answer

#define ll long long int


long totalTriplets(vector<int> arr, long k) {

    int n= arr.size();

    // occurence map for each element (indices)
    map<ll, vector<ll>> occ;

    for(ll i = 0; i < n; i++){
        occ[arr[i]].push_back(i);
    }

    // answer
    ll ans = 0;

    for(ll i = 0; i < n-1; i++){

        // take pair
        ll currentProduct = (1ll*arr[i])*(1ll*arr[i+1]);

        // current product is zero
        if(currentProduct == 0){

            // if the target is also zero, then we can make triplets with the rest of the elements.
            if(k == 0) ans += (n-2);
            
            // else not possible, try next pair
            continue;
        }

        // the currentProduct does not divide k completely so it is not possible to find the third element 
        if( k%currentProduct != 0 ) continue;

        // third element that we have to find
        ll rem = k/currentProduct;

        // find the count of the third element in the left part of the array.
        ans += (upper_bound(occ[rem].begin(), occ[rem].end(), i-1)
             -lower_bound(occ[rem].begin(), occ[rem].end(), 0));

        // find the count of the third element in the right part of the array.
        ans += upper_bound(occ[rem].begin(), occ[rem].end(), n-1)
             -lower_bound(occ[rem].begin(), occ[rem].end(), i+2);
    }

    // count the number of adjacent triplets in array
    for(ll i = 0; i < n-2; i++){
        if((1ll*arr[i]) * (1ll*arr[i+1]) * (1ll*arr[i+2]) == k) ans--;
    }
    
    return ans;
}