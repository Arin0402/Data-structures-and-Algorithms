#include <bits/stdc++.h>
using namespace std;

// 1
// O(nlogn)(sorting) +  O(n^2)( searching for slot) ;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    static bool cmp(Job a, Job b)
    {

        return a.profit > b.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {

        int maxDeadline = 0;

        for (int i = 0; i < n; i++)
            maxDeadline = max(maxDeadline, arr[i].dead);

        vector<int> allocation(maxDeadline, -1);

        sort(arr, arr + n, cmp);

        int totalProfit = 0;
        int totalJobsDone = 0;

        for (int i = 0; i < n; i++)
        {

            int ind = arr[i].dead - 1;

            while (ind >= 0)
            {

                if (allocation[ind] != -1)
                    ind--;
                else
                {
                    allocation[ind] = arr[i].profit;
                    totalJobsDone++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> ans;

        ans.push_back(totalJobsDone);
        ans.push_back(totalProfit);

        return ans;
    }
};

// 2
// Disjoint set.
// a little complex ,
// can get the intution by watching gfg video.
// https://youtu.be/RcomoqzZMF4?t=860