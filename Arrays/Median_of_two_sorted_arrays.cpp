// https://www.youtube.com/watch?v=NTop3VTjmxk
#include <bits/stdc++.h>
using namespace std;

double Median(vector<int> &A, vector<int> &B)
{

    if (B.size() > A.size())
        return Median(B, A); // swapping to make A samller

    int n1 = A.size();
    int n2 = B.size();
    int low = 0;
    int high = n1;

    while (low <= high)
    {

        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0 ? INT_MIN : A[cut1 - 1]);
        int left2 = (cut2 == 0 ? INT_MIN : B[cut2 - 1]);

        int right1 = (cut1 == n1 ? INT_MAX : A[cut1]);
        int right2 = (cut2 == n2 ? INT_MAX : B[cut2]);

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
            low = cut1 + 1;
    }

    return 0.0;
}

int main()
{
    vector<int> arr1 = {-5, 3, 6, 12, 15};
    vector<int> arr2 = {-12, -10, -6, -3, 4, 10};
    cout << "Median of the two arrays are" << endl;
    cout << Median(arr1, arr2);
    return 0;
}