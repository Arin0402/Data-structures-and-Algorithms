#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0

// 1
// memo
// O(N*target)
// O(N*target) + O(N)
int code(int ind, int target, vector<vector<int>> &dp, vector<int> arr)
{
    if (ind < 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    // OR

    // if(ind == 0){
    //     if(target == 0 && arr[0] == 0) return 2;
    //     if(target == 0 || arr[0] == target) return 1;
    //     return 0;
    // }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int take = 0;

    if (arr[ind] <= target)
        take = code(ind - 1, target - arr[ind], dp, arr);
    int not_take = code(ind - 1, target, dp, arr);

    dp[ind][target] = (take + not_take) % 1000000007;
}
int countPartitions(int n, int d, vector<int> &arr)
{

    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if ((total - d) & 1 == 1)
        return 0;

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));

    return code(n - 1, (total - d) / 2, dp, arr);
}

// 2
// O(N*target)
// O(N*target)

int countPartitions(int n, int d, vector<int> &arr) {
    
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];


    int target = (d + total);

    if(target%2 != 0) return 0;

    target /= 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else {
        dp[0][0] = 1;
        if(arr[0] <= target) dp[0][arr[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){

            // not_take
            int choice1 = dp[i - 1][j];

            // take
            int choice2 = 0;
            if(arr[i] <= j) choice2 = dp[i - 1][j - arr[i]];

            dp[i][j] = (choice1 + choice2)%MOD;   
        }
    }

    return dp[n - 1][target];
    

}

// OR

class Solution {
  public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
    
        int total = 0;
        for (int i = 0; i < n; i++)
            total += arr[i];
            
        if(total - d < 0) return 0;
    
        if ((total - d) & 1 == 1)
            return 0;
    
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
        
        int target = (total - d) / 2;
        
        for(int i = 0; i <= n; i++){
            
            for(int j = 0; j <= target; j++){
                
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    
                    int take = 0;
                    int not_take = 0;
    
                    if (i-1 >=0 && j - arr[i-1] >= 0 && arr[i - 1] <= target)
                        take = dp[i - 1][j - arr[i-1]]; 
                    
                    if(i-1 >= 0)    
                        not_take = dp[i - 1][j];
                
                    dp[i][j] = (take + not_take) % 1000000007;
                }
                
            }
        }
        
    
        return dp[n][(total - d) / 2];
    }

};
