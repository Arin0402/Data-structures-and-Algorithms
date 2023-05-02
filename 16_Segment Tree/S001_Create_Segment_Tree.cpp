#include <bits/stdc++.h>
using namespace std;

int nums[100000], seg[4 * 100000];

void build(int ind, int low, int high)
{

    if (low == high)
    {
        seg[ind] = nums[low];
        return;
    }

    int mid = (low + high) / 2;

    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r)
{

    if (low >= l && high <= r)
        return seg[ind];

    if (l > high || low > r)
        return INT_MIN;

    int mid = (low + high) / 2;

    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    build(0, 0, n - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {

        int l, r;
        cin >> l >> r;

        cout << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}