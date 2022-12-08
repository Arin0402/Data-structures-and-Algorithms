//  https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
//  https://www.youtube.com/watch?v=m18Hntz4go8

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class solution
{

public:
        long long trappingWater(int arr[], int n)
    {
        long long int water = 0;
        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;

        while (left <= right)
        {

            if (arr[left] <= arr[right])
            {
                water += max(0, left_max - arr[left]);
                left_max = max(left_max, arr[left]);
                left++;
            }
            else
            {
                water += max(0, right_max - arr[right]);
                right_max = max(right_max, arr[right]);
                right--;
            }
        }

        return water;
    }
};
