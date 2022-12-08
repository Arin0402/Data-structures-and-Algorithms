#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/EKO/

// Apply binary search.
// the minimum cut which can be made will be at 0 meters. so low = 0;
// the maximum cut which can be made will be at the height of the highest tree so high = max(heights of tree).

// get the mid
// if we are able to obtain M meters of wood by making cut at mid . we will increase the height of the cut,
// so mid = low + 1;

// else high = mid - 1;