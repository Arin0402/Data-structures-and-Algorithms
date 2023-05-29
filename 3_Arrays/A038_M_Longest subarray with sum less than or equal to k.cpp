#include <bits/stdc++.h>
using namespace std;

// 1
// brute


// 2
// O(N + N*logN)
// using binary search
// we will apply binary search on lengths
// minimum length can be 0
// maximum length can be n

// for each length( mid ) check if the length can be the possible answer or not i.e if we can get the sum <= k for this particular length
// It can be checked easily using sliding window as the length is fixed
// we can also use prefix sum to check for a fixed length.

#define ll long long int

// check if the length is valid i.e if we can get the sum <= k for this particular length
bool ispeYesHaiYaNo(vector<ll> &pref, ll mid, ll n, ll k){

    for(ll ep = 1; ep <= n; ep++){
        
        ll sp = ep - mid + 1;
        if(sp < 1) continue;

        if(pref[ep]-pref[sp-1]<=k){
            return true;
        }
    }
    return false;
}

int main(){
    
    // input
    ll n, k; cin>>n>>k;
    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    // creating prefix array to check for a particular length
    vector<ll> pref(n+1, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];

    // bianry search on length
    ll lo = 0, hi = n, ans = -1;

    while(lo <= hi){

        ll mid = (lo+hi)/2;

        if(ispeYesHaiYaNo(pref, mid, n, k)){

            // possible answer
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }  
    cout<<ans<<endl;
}


// 3
// sliding window
// O(N)

// An efficient approach is to use the sliding window technique. 

// - Traverse the array and check if on adding the current element its sum is less than or equal to k.
// - If it’s less than k then add it to the sum and increase the count.
// - Keep track of Maximum count.

int atMostSum(int arr[], int n, int k)
{
    int sum = 0;
    int cnt = 0, maxcnt = 0;
 
    for (int i = 0; i < n; i++) {
         
        // If adding current element doesn't
        // cross limit add it to current window
        if ((sum + arr[i]) <= k) {
            sum += arr[i];
            cnt++;
        }
 
        // Else, remove first element of current
        // window and add the current element
        else if(sum!=0)
        {
            sum = sum - arr[i - cnt] + arr[i];
        }
 
        // keep track of max length.
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}
 