#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/GERGOVIA/

// person will purchase the item from the shop which is closest possible.
int main()
{

	while (true)
	{

		int n;
		cin >> n;

		if (n == 0)
			break;

		// Note - it can solved without using extra space for positives and negatives.
		// just use two poinetrs for buy and sell.
		// if need intution , anuj bhaiya

		vector<pair<int, int>> positives; // all buy .
		vector<pair<int, int>> negatives; // all sell.

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;

			if (x >= 0)
				positives.push_back({x, i});
			else
				negatives.push_back({-1 * x, i});
		}

		int p1 = 0;
		int p2 = 0;

		long long int ans = 0;

		// Two pointer approach.
		while (p1 < positives.size() && p2 < negatives.size())
		{

			int buy = positives[p1].first;
			int sell = negatives[p2].first;

			int buyInd = positives[p1].second;
			int sellInd = negatives[p2].second;

			if (buy == sell)
			{
				ans += buy * (abs((buyInd - sellInd)));
				p1++;
				p2++;
			}
			else if (buy > sell)
			{

				positives[p1].first -= sell;			 // decrease the demand.
				ans += sell * (abs((buyInd - sellInd))); // add to the answer.
				p2++;
			}
			else
			{

				negatives[p2].first -= buy;
				ans += buy * (abs((buyInd - sellInd)));
				p1++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
