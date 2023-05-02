#include <bits/stdc++.h>
using namespace std;

// 1
// using queue
// O(N*C)
class Solution
{
public:
    void helper(queue<int> &cache, int cacheSize, int page, int &faults)
    {

        vector<int> arr;
        bool found = false; // if element is already present or not.

        int C = cache.size();

        while (!cache.empty())
        {

            // element is foound. so do not insert in arr.
            if (cache.front() == page)
            {
                found = true;
            }
            else
                arr.push_back(cache.front());

            cache.pop();
        }

        if (found)
        {
            // insert the rest of the elements into cache.
            for (int i = 0; i < C - 1; i++)
                cache.push(arr[i]);

            // insert the found element at end in cache.
            cache.push(page);
        }
        // element is not found and cache is not full. so insert element at the end;
        else if (C < cacheSize)
        {

            // insert all the elements into cache.
            for (int i = 0; i < C; i++)
                cache.push(arr[i]);

            // insert the current element at the end;
            cache.push(page);
            faults++;
        }
        // element not found and cache is full.
        else
        {

            // we will remove the first element of the cache and insert the rest elements in to cache.
            for (int i = 1; i < C; i++)
                cache.push(arr[i]);

            // insert the current element at the end;
            cache.push(page);
            faults++;
        }
    }

    int pageFaults(int N, int C, int pages[])
    {

        // queue to store the pages.
        queue<int> cache;

        // insert the first page in the cache.
        cache.push(pages[0]);
        int faults = 1;

        // loop for the number of pages.
        for (int i = 1; i < N; i++)
        {

            helper(cache, C, pages[i], faults);
        }

        return faults;
    }
};