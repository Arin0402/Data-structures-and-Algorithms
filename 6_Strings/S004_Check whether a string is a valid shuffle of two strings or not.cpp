#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// sort the first string.
// for a window of size M(size of first string)
//      create a temp string.
//      insert elements of this window in temp.
//      sort temp.
//      compare the two strings.

// 2
// efficient
// create frequency array for the first string.
// crete frequency array for the window of size M of second string.
// use sliding window technique and compare.