// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int freq[100001] = {0};
        int start = 0, end = 0, length = 0, Max = 0;

        for (int i = 0; i < N; i++)
        {
            freq[arr[i]]++;
            Max = max(arr[i], Max);
        }

        while (start <= Max && end <= Max)
        {
            if (freq[end] > 0)
                end++;
            else
            {
                length = max(length, end - start);

                end = end + 1;
                start = end;
            }
        }
        length = max(length, end - start);
        return length;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends