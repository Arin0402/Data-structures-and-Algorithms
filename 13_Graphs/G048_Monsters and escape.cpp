#include <bits/stdc++.h>
using namespace std;

// - given a graph with coordinates of some monsters and a boy
// - the boy wants to escape the matrix. Exit is at the bottom right corner of the matrix

// - the monsters can move by one step in all four directions any number of times and can block the path of the boy so that he cannot escape
// - both the boy and monsters require 1 sec to take one step

// - we have to determine if the boy can escape the matrix or not

// Solution

// - the main jist of the question is that the monster can only block the path of the boy if any monster is able to reach a 
// a particular cell before the boy does.

// - So for every cell in the matrix, we would find the minimum time required to reach that cell by a monster( it can be any monster. we need the minimum time)

// - Then for every cell, we would calculate the minimum time required by the boy to reach that cell

// - Now a cell is safe to visit if and only if timeRequiredByBoy(i, j) < timeRequiredByMonster(i, j). create a new matrix and mark the safe states as TRUE and unsafe as false

// Now we only have to check if there exists path from the current position to the exit.


