#include <bits/stdc++.h>
using namespace std;

// 1
// naive
// for every element find product.

// 2
// prefix and suffix array
// TC - O(n)
// SC - O(n) + o(n)
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    long long int left[n], right[n];

    left[0] = 1;
    right[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<long long int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(left[i] * right[i]);

    return ans;
}

// 3
// no need to use extra space for prefix and suffix array.
// the prefix product is stored in answer array first.
// then traverse from back and calculate the result.
// SC - O(N)
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    vector<long long int> ans(n, 0);

    ans[0] = 1;

    // prefix product.
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    long long int temp = 1;

    for (int i = n - 1; i >= 0; i--)
    {

        ans[i] = temp * ans[i];

        temp = temp * nums[i]; // product of the elements from behind
    }

    return ans;
}

// 4
// store the product of all the elements in a variable.
// divide by element to get the result.
// handle the cases containing zero.
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
    
        vector<long long int> ans(n, 0);
    
        long long int var = 1;
    
        long long numOfZeros = 0;
    
        for (int i = 0; i < n; i++)
        {
    
            if (nums[i] == 0)
                numOfZeros++;
            else
                var *= nums[i];
                
            if (numOfZeros > 1)
                return ans;
        }
    
    
        for (int i = 0; i < n; i++)
        {
            
            if (numOfZeros == 0)
                ans[i] = var / nums[i];
            else if (numOfZeros == 1 && nums[i] != 0)
                ans[i] = 0;
            else if (numOfZeros == 1 && nums[i] == 0)
                ans[i] = var;
        }
    
        return ans;
    }
};
