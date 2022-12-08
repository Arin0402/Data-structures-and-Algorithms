#include <bits/stdc++.h>
using namespace std;

// Leetcode's 4 sum question.

// 1
// generate all the quadruples.
// use set to get the unique pairs.
// O(n^4)

// 2
// O(n^3)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // LOOP 1
        for (int i = 0; i < n - 3; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // escape for same number  - -7,-6,-6,2,3,3,4  Here -6.
                // cout<<"inside"<<endl;
            }

            // LOOP 2
            for (int j = i + 1; j < n - 2; j++)
            {

                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue; // escape for same number  - -7,-1, -1, 1, 1 3 ,4.
                              //- 2,2,2,2,2.

                long long int sum = nums[i] + nums[j]; // sum to bre searched.
                int low = j + 1;
                int high = n - 1;

                while (low < high)
                {

                    if (sum + nums[low] + nums[high] == target)
                    {

                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});

                        // avoiod repetiion of same pairs as we are not breaking out of the loop. - eg -7,-5,0,2,2,3,3 . Here for -5 .
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        low++;
                        high--;
                    }
                    else if (sum + nums[low] + nums[high] < target)
                    {
                        while (low < high && nums[low] == nums[low + 1])
                            low++;

                        low++;
                    }
                    else
                    {
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        high--;
                    }
                }
            }
        }

        return ans;
    }
};