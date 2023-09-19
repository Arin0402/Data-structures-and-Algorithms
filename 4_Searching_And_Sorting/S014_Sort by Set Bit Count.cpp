#include <bits/stdc++.h>
using namespace std;

// 1
// calculate the set bits for all the elements and store in the array.
// using insertion sort on set_bits_count array, we will swap in both the arrays.
// TC - O(n^2)
// SC - O(n)
class Solution
{
public:
    int setBitCount(int n)
    {
        int cnt = 0;

        while (n)
        {
            if (n & 1)
                cnt++;

            n = n >> 1;
        }
        return cnt;
    }

    void sortBySetBitCount(int arr[], int n)
    {

        int setBitCountArray[n];

        // calculate the set bits.
        for (int i = 0; i < n; i++)
            setBitCountArray[i] = setBitCount(arr[i]);

        int i = 1;

        // insertion sort.
        while (i < n)
        {

            int j = i;

            while (j > 0 && setBitCountArray[j] > setBitCountArray[j - 1])
            {

                swap(setBitCountArray[j], setBitCountArray[j - 1]);
                swap(arr[j], arr[j - 1]);
                j--;
            }

            i++;
        }
    }
};

// 2
// using stable sort (It uses merge sort in background).
//  O(nlogn)
class Solution
{
public:
    static int setBitCount(int n)
    {
        int cnt = 0;

        while (n)
        {

            if (n & 1)
                cnt++;

            n = n >> 1;
        }
        return cnt;
    }

    static int cmp(int a, int b)
    {

        int count1 = setBitCount(a);
        int count2 = setBitCount(b);

        if (count1 > count2)
            return true;
        return false;
    }

    void sortBySetBitCount(int arr[], int n)
    {

        stable_sort(arr, arr + n, cmp);
    }
};

// 3
// using count sort
// There can be a minimum 1 set-bit and only a maximum of 31set-bits in an integer.
// TC - O(n)
// Sc - O(n)
class Solution
{
public:
    int countBits(int a)
    {
        int count = 0;
        while (a)
        {
            if (a & 1)
                count += 1;
            a = a >> 1;
        }
        return count;
    }

    void sortBySetBitCount(int arr[], int n)
    {
        vector<vector<int>> count(32);
        int setbitcount = 0;

        for (int i = 0; i < n; i++)
        {
            setbitcount = countBits(arr[i]);
            count[setbitcount].push_back(arr[i]);
        }

        int j = 0;

        for (int i = 31; i >= 0; i--)
        {
            vector<int> v1 = count[i];
            for (int i = 0; i < v1.size(); i++)
                arr[j++] = v1[i];
        }
    }
};

// 4
// using map
// insert keys by multiplying by -1 (in order to get decreasing order)
// TC - O(nlogn)
// SC- O(n)
