#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
// https://www.youtube.com/waxtch?v=RrxpTWqj97A

// 1
// use pointers for each row and calculate the minimum and maximum
// store the result and then increase the minimum pointer.
// O(N*k*k) (k for compainring the elements of each row)

// 2
// using min heap
// O(N*k*logk)

#define N 1000

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        int mini = INT_MAX; // minimum element.
        int maxi = INT_MIN; // maximum element.

        // insert the starting elements of each row in pq.
        for (int i = 0; i < k; i++)
        {

            int element = KSortedArray[i][0];
            pq.push(new Node(element, i, 0));

            // update the mini and maxi.
            mini = min(mini, element);
            maxi = max(maxi, element);
        }

        // store the final answer
        int start = mini;
        int end = maxi;

        while (!pq.empty())
        {

            auto temp = pq.top();
            pq.pop();

            mini = temp->data;

            // found smaller range. update
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            // next element in the range.
            if (temp->col + 1 < n)
            {

                // next element in the row.
                int nextEle = KSortedArray[temp->row][temp->col + 1];

                // we need to compare the nextEle with maxi only
                // becuase this is the only element which is changing.
                maxi = max(maxi, nextEle);

                // push into queue.
                pq.push(new Node(nextEle, temp->row, temp->col + 1));
            }
            // one of the rows is exhausted so break
            else
                break;
        }

        return {start, end};
    }
};
