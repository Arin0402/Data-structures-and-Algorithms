#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int index, vector<int> &ds, int arr[], int n)
{

    if (index >= n)
    {
        for (auto it : ds)
            cout << it << " ";

        // empty subsequence;
        if (ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }

    // take the element
    ds.push_back(arr[index]);
    printSubsequences(index + 1, ds, arr, n);

    // not take the element
    ds.pop_back();
    printSubsequences(index + 1, ds, arr, n);
}
int main()
{

    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;

    printSubsequences(0, ds, arr, n);

    // TC - near about 2^n * n (n for printing the subsequence)
    // SC - O(n)  maxdepth of recursion tree is n so not more than n calls will be waiting in the stack;
}