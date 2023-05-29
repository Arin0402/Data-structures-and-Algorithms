#include <bits/stdc++.h>
using namespace std;

// Find the largest area of square submatrix having sum <= k.
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/


// apply binary search
// length 0  to n

// create 2d prefix of the matrix

// check for each length(mid) if the sum is <= k
// it can be checked using prefix matrix ( use for loops to check for each matrix of length mid)

#define ll long long int

bool ispeYesHaiYaNo(vector<vector<ll>> &pref, ll mid, ll n, ll k){

    // check for each submatrix of length mid
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){

            ll sp = i-mid+1, ep = j-mid+1;

            if(sp<=0 or ep<=0) continue;

            ll sum = pref[i][j]-pref[sp-1][j]-pref[i][ep-1]+pref[sp-1][ep-1];

            if(sum<=k) return true;
        }
    }
    return false;
}

int main(){
    
    // input
    ll n, k; cin>>n>>k;
    vector<vector<ll>> arr(n+1, vector<ll>(n+1, 0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++) cin>>arr[i][j];
    }
    
    // create prefix matrix
    vector<vector<ll>> pref(n+1, vector<ll>(n+1, 0));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }

    // binary search
    ll lo = 0, hi = n, ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(ispeYesHaiYaNo(pref, mid, n, k)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }  

    // return area
    cout<<ans*ans<<endl;
}
