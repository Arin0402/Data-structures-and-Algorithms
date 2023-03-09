#include <bits/stdc++.h>
using namespace std;

// 1
// https://practice.geeksforgeeks.org/problems/07e45fe40846bc670ad2507d2c649304699768b9/1


// Steps:-

// Covert the given query into binary form and store it in the array named set.
// Keep an answer variable to store the answer.
// Now run a loop over the set array from the most significant bit towards the least significant bit.
// Check if the ith bit and (i-1)th bit is set then unset the (i-2)th bit so that 3 consecutive bit must not be set.
// And also take the bitwiseOR operation with answer and 2i , to add the all set bit values.
// Return the answer.

class Solution {

  public:
    int noConseBits(int n) {
        int set[35];

        for (int j = 0; j < 35; j++) set[j] = 0;

        for (int j = 30; j >= 0; j--) {
            if ((1 << j) & n) {
                set[j] = 1;
            }
        }
        int fin_ans = 0;
        for (int j = 30; j >= 2; j--) {
            if (set[j] == 1) {
                fin_ans |= (1 << j);
                if (set[j - 1] == 1) {
                    set[j - 2] = 0;
                }
            }
        }
        if (set[1] == 1) fin_ans |= 2;
        if (set[0] == 1) fin_ans |= 1;

        return fin_ans;
    }
};
