#include <iostream>
using namespace std;

bool isPossible(int ranks[], int cooks, int parathasRequired, int time)
{

	// total parathas made.
	int parathasMade = 0;

	// loop for each cook.
	for (int i = 0; i < cooks; i++)
	{

		int rank = ranks[i];

		int paranthaCnt = 0;
		int totalTime = rank;

		// check the parathas made by this cook under the given time.
		while (totalTime <= time)
		{
			paranthaCnt++;
			totalTime += rank * (paranthaCnt + 1);
		}

		parathasMade += paranthaCnt;

		// possible to make all the parathas under the given time.
		if (parathasMade >= parathasRequired)
			return true;
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

		// maximum ranks among all the ranks.
		int maxRank = 0;

		for (int i = 0; i < cooks; i++)
		{
			cin >> ranks[i];
			maxRank = max(maxRank, ranks[i]);
		}

		// minumum time can be taken as 1.
		int low = 1;

		// maximum time will be time required by the max Rank cook to cook all the parathas.
		int high = maxRank * ((parathas * (parathas + 1)) / 2);

		int res = -1;

		while (low <= high)
		{

			int mid = low + (high - low) / 2;

			if (isPossible(ranks, cooks, parathas, mid))
			{

				res = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}

		cout << res << endl;
	}
	return 0;
}