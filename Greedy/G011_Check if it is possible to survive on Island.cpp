#include <bits/stdc++.h>
using namespace std;

// O(1)
class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {

        int sundays = S / 7;

        // cannot buy on sundays.
        int buyingDays = S - sundays;

        int TotalFood = S * M;

        int daysRequiredToBuyFood = 0;

        if (TotalFood % N == 0)
        {
            daysRequiredToBuyFood = TotalFood / N;
        }
        else
        {
            daysRequiredToBuyFood = TotalFood / N + 1;
        }

        if (buyingDays >= daysRequiredToBuyFood)
            return daysRequiredToBuyFood;
        return -1;
    }
};