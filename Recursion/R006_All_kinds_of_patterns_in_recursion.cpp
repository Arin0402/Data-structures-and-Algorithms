#include <bits/stdc++.h>
using namespace std;

// 1. function to print subsequences whose sum is equal to k;
void printSubsequences(int index, vector<int> &ds, int arr[], int n, int sum, int k)
{

    if (index >= n)
    {
        if (sum == k)
        {
            for (auto i : ds)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    // take
    ds.push_back(arr[index]);
    sum += arr[index];
    printSubsequences(index + 1, ds, arr, n, sum, k);

    // not take
    ds.pop_back();
    sum -= arr[index];
    printSubsequences(index + 1, ds, arr, n, sum, k);
}

// 2. program to print only one subsequence whose su is equal to k;
bool printanyOneSubsequence(int index, vector<int> ds, int arr[], int n, int sum, int k)
{

    bool flag = false;
    if (index >= n)
    {
        if (sum == k)
        {
            for (auto i : ds)
                cout << i << " ";
            cout << endl;
            flag = true;
            return flag;
        }
        return false;
    }

    ds.push_back(arr[index]);
    sum += arr[index];
    if (printanyOneSubsequence(index + 1, ds, arr, n, sum, k))
        return true;

    ds.pop_back();
    sum -= arr[index];
    if (printanyOneSubsequence(index + 1, ds, arr, n, sum, k))
        return true;

    return false;
}

// 3. function to print count of subsequences whose sum is equal to k;
int printcountofsubsequences(int index, vector<int> &ds, int arr[], int n, int sum, int k)
{

    if (index >= n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    // take
    ds.push_back(arr[index]);
    sum += arr[index];
    int l = printcountofsubsequences(index + 1, ds, arr, n, sum, k);

    // not take
    ds.pop_back();
    sum -= arr[index];
    int r = printcountofsubsequences(index + 1, ds, arr, n, sum, k);

    return l + r;
}

int main()
{

    int arr[] = {1, 2, 1};
    int k = 2;
    int n = 3;

    vector<int> ds;

    // printSubsequences(0, ds, arr, n, 0, k);
    // printanyOneSubsequence(0, ds, arr, n, 0, k);

    cout << printcountofsubsequences(0, ds, arr, n, 0, k);
}
