#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int helper(int health, int armour, string place)
{

	// die.
	if (health <= 0 || armour <= 0)
		return 0;

	// already solved.
	if (dp[health][armour] != -1)
		return dp[health][armour];

	int x = 0, y = 0, z = 0;

	// can go to other two places.
	if (place != "air")
		x = helper(health + 3, armour + 2, "air");
	if (place != "water")
		y = helper(health - 5, armour - 10, "water");
	if (place != "fire")
		z = helper(health - 20, armour + 5, "fire");

	// find the maximum answer from that two places.
	return dp[health][armour] = 1 + max({x, y, z});
}

int main()
{

	int t;
	cin >> t;

	while (t--)
	{

		int health, armour;
		cin >> health >> armour;

		// set up the dp array.
		memset(dp, -1, sizeof(dp));

		// we select air first as it woukd be most beneficial the three options.
		cout << helper(health + 3, armour + 2, "air") << endl;
	}
	return 0;
}