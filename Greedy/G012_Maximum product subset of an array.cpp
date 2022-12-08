#include <bits/stdc++.h>
using namespace std;

// 1
// O(n)

// If there are even number of negative numbers and no zeros, result is simply product of all
// If there are odd number of negative numbers and no zeros, result is product of all except the
// negative integer with the least absolute value.
// If there are zeros, result is product of all except these zeros with one exceptional case.
// The exceptional case is when there is one negative number and all other elements are 0.
// In this case, result is 0.