#include <bits/stdc++.h>
using namespace std;

// Given an array of integers, and with Q queries L R X, compute the number of occurrences of X in range [L, R]

// 1
// brute 
// iterate and count    

// 2
// create the map as the previous question 

// find the first and last occurence of the element in the range l and r
// ans ->  lastOccurence - firstOccurence + 1
#define ll long long int

// first occurence
ll fstOccurence(ll x, ll y, map<ll,vector<ll>> &occ){

    ll lo = 0, hi = ((ll)occ[x].size())-1;
    ll ans = -1;

    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(occ[x][mid]<y){
            lo = mid+1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }
    return ans;

}

// last occurence
ll lstOccurence(ll x, ll y, map<ll,vector<ll>> &occ){
    ll lo = 0, hi = ((ll)occ[x].size())-1;
    ll ans = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(occ[x][mid]>y){
            hi = mid-1;
        }
        else{
            ans = mid;
            lo = mid+1;
        }
    }
    return ans;
}


int main(){

    // input
    ll n; cin>>n;
    vector<ll> arr(n, 0);
    for(ll i=0;i<n;i++) cin>>arr[i];

    // map
    map<ll,vector<ll>> occ;
    for(ll i=0;i<n;i++){
        occ[arr[i]].push_back(i);
    }  
    

    // queries
    ll q; cin>>q;

    while(q--){

        ll l, r, x; cin>>l>>r>>x;

        // find the first and last occurence
        ll ans1 = fstOccurence(x, l, occ);
        ll ans2 = lstOccurence(x, r, occ);
        
        if(ans1==-1 or ans2==-1) cout<<"0"<<endl;
        else cout<<ans2-ans1+1<<endl;
    }
}

