#include <bits/stdc++.h>
using namespace std;

// codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=0

int countCustomers(vector<int> &arr, int k)
{
    int n = arr.size();

    // to store the status of the persons.
    // 0 -> not visited.
    // 1 -> occupied.
    // 2 -> left.

    vector<int> status(n / 2 + 1, 0);

    int cnt = 0; // number of pcs occupied.
    int ans = 0; // persons who didn't got chance.

    for (int i = 0; i < n; i++)
    {
        int person = arr[i];

        if (cnt == k)
        { // all are occupied.

            // first time visiting.
            if (status[person] == 0)
            {
                status[person] = 2;
                ans++;
            }
            // leaving the system.
            else if (status[person] == 1)
            {
                status[person] = 2;
                cnt--;
            }
        }
        else
        {

            if (status[person] == 0)
            {
                cnt++;
                status[person] = 1;
            }
            else if (status[person] == 1)
            {
                cnt--;
                status[person] = 2; // left.
            }
        }
    }

    return ans;
}
