#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-index3307/1

// 1
// two loops
// O(N^2)

// 2
// A quick observation actually shows that we have been looking to find the first greatest element traversing from the end of the array to the current index. We can see that we are trying to find the first greatest element again and again for each element in the array. Let's say we have an array with us for example [1, 5, 12, 4, 9] now we know that 9 is the element that is greater than 1, 5, and 4 but why do we need to find that again and again. We can actually keep a track of the maximum number moving from the end to the start of the array. The approach will help us understand better and also this improvisation is great to come up with in an interview. 

// - Traverse the array from the end and keep a track of the maximum number to the right of the current index including self
// - Now we have a monotonous decreasing array, and we know we can use binary search to find the index of the rightmost greater element
// - Now we will just use binary search for each of the elements in the array and store the maximum difference of the indices and that's it we are done.
