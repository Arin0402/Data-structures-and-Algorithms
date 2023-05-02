#include <bits/stdc++.h>
using namespace std;

// 1
// Normal sort
// o(logn)

// 2
// use partitoin function of quick sort only once.
// o(n)

// 3
// Two pointer
// - Check If the left and right pointer elements are negative then simply increment the left pointer.
// - Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
// - Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
// - Repeat the above 3 steps until the left pointer ≤ right pointer.
// O(n)

