#include <bits/stdc++.h>
using namespace std;


// given the position of bulbs at the street and strength of the bulbs
// the bulb with strength x can light up the street form i - x to i + x
// we have to find the number of indices where no light would be coming

// Solution

// calculate the range for each bulb where it would be thowing light (ex [3, 5]);
// create a array of size street and initiliaze with 0
// we will use the concept of difference array.

// for ex if the range for a bulb is [3, 5];

//      then at index 3, set street[3] = 1
//      at index 6, set street[6] = -1

// do this for every bulb


// find the prefix sum of the street array, and count the number of zeros in it.
// It woud be our answer

#define ll long long int

int main(){
    

    ll n,k; cin>>n>>k;    

    vector<ll> pos(k, 0), power(k, 0);

    // input    
    for(ll i=0;i<k;i++) cin>>pos[i];
    for(ll i=0;i<k;i++) cin>>power[i];
   
    vector<ll> apniArray(n+2, 0), pref(n+2, 0);

    // update the indixes
    for(ll i=0;i<k;i++){
        ll L = max(1ll, pos[i]-power[i]);
        ll R = min(n, pos[i]+power[i]);
        apniArray[L]+=1;
        apniArray[R+1]-=1;
    }

    // calculate the prefix array
    for(ll i=1;i<=n;i++) 
        pref[i]=pref[i-1]+apniArray[i];

    // calculate the number of zeros
    ll noOfZeroes = 0;
    for(ll i=1;i<=n;i++) 
        if(pref[i]==0) noOfZeroes++;

    cout<<noOfZeroes<<endl;
   
}