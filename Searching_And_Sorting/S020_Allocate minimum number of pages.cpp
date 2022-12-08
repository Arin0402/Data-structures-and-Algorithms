#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minof(int A[], int N)
    {

        int mini = A[0];

        for (int i = 1; i < N; i++)
            mini = min(mini, A[i]);

        return mini;
    }

    int sumof(int A[], int N)
    {

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += A[i];

        return sum;
    }

    bool isPossible(int A[], int N, int M, int pages)
    {

        int studentsAlloted = 1; // number of students that has been alloted books.
        int pagesAlloted = 0;

        for (int i = 0; i < N; i++)
        {

            if (A[i] > pages)
                return false;
            // pages alloted to a student is greater than allowed value.
            if (pagesAlloted + A[i] > pages)
            {

                studentsAlloted++;
                pagesAlloted = A[i];

                // more students are alloted books than mentioned value, so return false.
                if (studentsAlloted > M)
                    return false;
            }
            // possible to allot pages.
            else
                pagesAlloted += A[i];
        }

        return true;
    }

    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        // low will be the minimum of pages available.
        int low = minof(A, N);

        // high will be the sum of all the pages.
        int high = sumof(A, N);

        int res = -1;

        // number of students are greater than number of books. so not possible.
        if (M > N)
            return -1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (isPossible(A, N, M, mid))
            {

                res = mid;

                // check if allocation is possible for the pages lesser than mid.
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return res;
    }
};