#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/majority-element-ii_893027?leftPanelTab=0 

// find all the elements in arrray whicH appears more than n/3 times.

// 1
// naive 
// traverse array for each element and check;
// O(n^2)

// 2
// using hashing
// O(n)
// O(n)

// 3
// Moore voting algorithm

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int count1 = 0;
    int count2 = 0;
    int ele1;
    int ele2;


    for(int i = 0; i < n; i++ ){
                
        if(count1 ==0 && arr[i] != ele2){
            count1 = 1;
            ele1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != ele1 ){
            count2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) count1++;
        else if(arr[i] == ele2) count2++;
        else{
            count1--;
            count2--;
        }
    }

    vector<int> ans;


    // now make sure that they are actually majority element
    count1 = 0;
    count2 = 0;

    int minCount = (int)n/3  + 1;

    for(int i =0 ; i < n; i++){

        if(arr[i] == ele1) count1++;
        else if (arr[i] == ele2) count2++;

    }

    if(count1 >= minCount ) ans.push_back(ele1);
    if(count2 >= minCount ) ans.push_back(ele2);

    sort(ans.begin(), ans.end());

    return ans;

}

            