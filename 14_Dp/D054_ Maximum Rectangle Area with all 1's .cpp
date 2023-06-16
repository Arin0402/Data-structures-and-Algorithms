#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// https://practice.geeksforgeeks.org/problems/max-rectangle/1

// 1
// O(n*m)(for FOR loops) + O(n*n)( for every row , we are calling the histogram function which takes O(n) time)
// O(n)
class Solution
{
public:
    void leftBoundary(vector<int> &left, vector<int> &heights, int n)
    {

        stack<int> st;
        left[0] = 0;
        st.push(0);

        for (int i = 1; i < n; i++)
        {

            while (!st.empty())
            {

                int ind = st.top();
                if (heights[ind] >= heights[i])
                    st.pop();
                else
                {
                    left[i] = ind + 1;
                    break;
                }
            }

            if (st.empty())
            {
                left[i] = 0;
            }

            st.push(i);
        }
    }

    void rightBoundary(vector<int> &right, vector<int> &heights, int n)
    {

        stack<int> st;
        right[n - 1] = n - 1;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {

            while (!st.empty())
            {

                int ind = st.top();
                if (heights[ind] >= heights[i])
                    st.pop();
                else
                {
                    right[i] = ind - 1;
                    break;
                }
            }

            if (st.empty())
            {
                right[i] = n - 1;
            }

            st.push(i);
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        leftBoundary(left, heights, n);
        rightBoundary(right, heights, n);

        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            maxi = max(( right[i] - left[i] + 1 ) * heights[i], maxi);
        }

        return maxi;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {

        vector<int> heights(m, 0);

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (M[i][j] == 1)
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            maxi = max(maxi, largestRectangleArea(heights));
        }

        return maxi;
    }
};
