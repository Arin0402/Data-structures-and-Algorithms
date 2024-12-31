#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.o rg/problems/calculate-the-coefficient/0?page=1&sortBy=newest&query=page1sortBynewest
// https://www.youtube.com/watch?v=Ebj83h76VUU

class Solution
{
public:
    int permutationCoeff(int n, int k)
    {

        long long int ans = 1;
        int count = 0;

        while(count < k)
        {
            ans = (n * ans) % 1000000007;
            count++;
            n--;
        }

        return ans;
    }
};
