#include <bits/stdc++.h>
using namespace std;

// number of parathas made by single chef in the giveTime.
// we are applying binary search here.
// we could also use iterative method to count the number of parathas made in giveTime
int parathasMadeBySingleChef(int rank, int givenTime, int requiredParathas){
	
	// minimum parathas that can be made -> 0
	// maximum parathas that can be made -> requiredParathas ( it is possible that the current chef could make all the parathas)
	int low = 0 , high = requiredParathas;
	
	int ans = 0;
	
	// binary search on number of parathas
	
	while(low <= high){
		
		// parathas
		int mid = low + (high - low)/2;
		
		// time required to make mid parathas
		int timeRequiredToMakeMidParathas = rank*( mid *(mid + 1)/2);
		
		// possible
		if(timeRequiredToMakeMidParathas <= givenTime ){
			ans = mid;
			
			// increase the number of parathas
			low = mid + 1;
		}
		else high = mid -1;
		
		
	}
	
	return ans;
	
	
}

// if it is possible to make parathas in mid time
bool isPossible(int givenTime , int requiredParathas, int ranks[], int n){
	
	// total parathas made by all the chefs
	int totalParathasMade = 0;
	
	// check for each chef
	for(int i = 0; i < n; i++){
		
		int rank = ranks[i];
		
		// add the parathas made by the current chef in the giveTime
		totalParathasMade += parathasMadeBySingleChef(rank, givenTime, requiredParathas);
		
		// possible to make
		if(totalParathasMade >= requiredParathas) return true;
		
	}
	
	return false;
	
}


int main()
{

	int t;
	cin >> t;

	while (t--)
	{

		int parathas;
		cin >> parathas;

		int cooks;
		cin >> cooks;

		int ranks[cooks];
		
		for(int i = 0; i < cooks; i++) cin>>ranks[i];
		
		int maxRank = INT_MIN;
		
		for(int i = 0; i < cooks; i++) maxRank = max(maxRank, ranks[i]);
		
		// minimum time required
		int low = 1;
		
		// man=ximum time required would be equal to the time required by the chef with the maximum rank to make all the parathas
		int high = maxRank*((parathas)*(parathas + 1)/2);
		
		int ans = -1;
		
		// binary search on time
		while(low <= high){
			
			// time
			int mid = low + (high - low)/2;
			
			// is it possible to make in mid time
			if(isPossible(mid, parathas, ranks, cooks)){
				
				ans = mid;
				
				// if possible in mid time, then it would also be possible to make in time > mid
				high = mid -1;
				
			}
			else low = mid + 1;
			
			
		}
		
		cout << ans << endl;
		
	}
	return 0;
}