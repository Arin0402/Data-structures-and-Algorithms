// https://www.youtube.com/watch?v=LuLCLgMElus

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    void reverse(vector<int> &arr, int start)
    {
        int end = arr.size() - 1;

        while (start < end)
        {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }

    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();

        int break_point = -1, swap_ind = 0;

        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
            {
                break_point = i - 1;
                break;
            }
        }

        if (break_point >= 0)
        {
            for (int i = n - 1; i > 0; i--)
            {
                if (arr[i] > arr[break_point])
                {
                    swap_ind = i;
                    break;
                }
            }

            swap(&arr[swap_ind], &arr[break_point]);
        }
        reverse(arr, break_point + 1);
    }
};
