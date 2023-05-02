#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {

        return a.first > b.first;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        vector<pair<double, Item>> order;

        for (int i = 0; i < n; i++)
        {

            int value = arr[i].value;
            int weight = arr[i].weight;

            // get the profit per kg.
            double profitPerKg = (1.0) * value / weight;

            order.push_back({profitPerKg, arr[i]});
        }

        // sort on the basis of profit per kg.
        // descending order.
        sort(order.begin(), order.end(), cmp);

        double profit = 0;
        int knapsack = 0;

        // counter of items.
        int i = 0;

        while (i < n && knapsack < W)
        {

            double profitPerKg = order[i].first;
            Item p = order[i].second;

            int value = p.value;
            int weight = p.weight;

            // can put whole element into knapsack.
            if (knapsack + weight <= W)
            {
                knapsack += weight;
                profit += value;

                i++;
            }

            // only put some part of it.
            else
            {
                profit += profitPerKg * (W - knapsack);
                break;
            }
        }

        return profit;
    }
};
