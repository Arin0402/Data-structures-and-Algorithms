#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

// same as previous
// just one condition change

class Solution
{
public:
    void merge(int l, int mid, int r, vector<int> &ans, vector<pair<int, int>> &temp)
    {

        int n1 = mid - l + 1;
        int n2 = r - mid;

        pair<int, int> arr1[n1];
        pair<int, int> arr2[n2];

        for (int i = 0; i < n1; i++)
        {
            arr1[i].first = temp[l + i].first;
            arr1[i].second = temp[l + i].second;
        }

        for (int i = 0; i < n2; i++)
        {
            arr2[i].first = temp[mid + 1 + i].first;
            arr2[i].second = temp[mid + 1 + i].second;
        }

        // index of arr1
        int i = 0;

        // index of arr2
        int j = 0;

        // index of temp.
        // to update the values
        // it will be equal to the l
        int k = l;

        while (i < n1 && j < n2)
        {

            int elementFirst = arr1[i].first;
            int indexFirst = arr1[i].second;

            int elementSecond = arr2[j].first;
            int indexSecond = arr2[j].second;

            // !----------------NOTE---------------------!
            // only this  operator ( > ) has been changed to ( < )
            // whole code is as it is
            // element of arr1 is smaller than element of arr2.

            if (elementFirst < elementSecond)
            {

                // add the count
                ans[indexFirst] += (n2 - j);

                temp[k].first = elementFirst;
                temp[k].second = indexFirst;

                i++;
            }
            else
            {

                temp[k].first = elementSecond;
                temp[k].second = indexSecond;
                j++;
            }
            k++;
        }

        while (i < n1)
        {

            int elementFirst = arr1[i].first;
            int indexFirst = arr1[i].second;

            temp[k].first = elementFirst;
            temp[k].second = indexFirst;
            i++;
            k++;
        }

        while (j < n2)
        {
            int elementSecond = arr2[j].first;
            int indexSecond = arr2[j].second;
            temp[k].first = elementSecond;
            temp[k].second = indexSecond;
            j++;
            k++;
        }
    }
    void mergeSort(int l, int r, vector<int> &ans, vector<pair<int, int>> &temp)
    {

        if (l < r)
        {

            int mid = l + (r - l) / 2;

            mergeSort(l, mid, ans, temp);
            mergeSort(mid + 1, r, ans, temp);

            merge(l, mid, r, ans, temp);
        }
    }

    vector<int> count_NGE(int n, vector<int> &nums, int queries, vector<int> &indices)
    {

        int l = 0;
        int r = n - 1;

        // answer vector
        vector<int> count(n, 0);

        // create new vector that will contain index also
        // element + index
        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++)
        {
            temp.push_back(make_pair(nums[i], i));
        }

        mergeSort(l, r, count, temp);

        vector<int> ans;

        for (int i = 0; i < queries; i++)
        {

            int ind = indices[i];
            ans.push_back(count[ind]);
        }

        return ans;
    }
};