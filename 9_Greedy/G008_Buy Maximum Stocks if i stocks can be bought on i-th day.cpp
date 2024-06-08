#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {

        // idea is to buy the stocks which have least price.

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
        {

            arr.push_back(make_pair(price[i], i + 1));
        }

        // sort on the basis of the prices.
        sort(arr.begin(), arr.end());

        int ans = 0;
        int i = 0;

        while (i < n && k > 0)
        {

            int amount = arr[i].first;
            int stocks = arr[i].second;

            int val = amount * stocks;

            if (val <= k)
            {
                ans += stocks;
                k -= val;
            }
            else
            {
                ans += k / amount;
                break;
            }

            i++;
        }

        return ans;
    }
};
