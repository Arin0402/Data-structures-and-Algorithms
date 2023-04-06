#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/asteroid-collision/1

// 1
// just understand the concept
// do not go for the solution, It contains way too much if else

// So there is just 1 main point that we need to focus on, and that is -: the collision will only happen when top of stack is a +ve number and the element we want to insert is -ve.

// And the reason for that is,

// If both elements are of same sign they will continue in that direction itself.
// If the top is -ve and the element we want to insert is +ve then they will continue in opposite directions.
// In both of these cases there will be no collision.

// We will always push on the stack in case the stack is empty.

// keep poping from the stack while the absolute value of negative element is greater than the positive element in the stack