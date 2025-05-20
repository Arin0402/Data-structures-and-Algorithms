// https://leetcode.com/problems/online-election/solutions/173382/c-java-python-binary-search-in-times/

#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate
{
public:
    vector<int> persons;
    vector<int> times;
    vector<int> whoIsLeading;

    int maxVoted = 0;
    int maxVotedCount = 0;

    // person, votes
    unordered_map<int, int> mp;

    int n;

    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        this->persons = persons;
        this->times = times;
        this->n = persons.size();

        for (int i = 0; i < n; i++)
        {
            int time = times[i];
            int personVoted = persons[i];

            if (mp.find(personVoted) == mp.end())
            {
                mp[personVoted] = 1;
            }
            else
                mp[personVoted]++;

            // highest voted candidate till now
            if (mp[personVoted] >= maxVotedCount)
            {
                maxVoted = personVoted;
                maxVotedCount = mp[personVoted];
            }

            whoIsLeading.push_back(maxVoted);
        }
    }

    int q(int t)
    {

        int ind = lower_bound(times.begin(), times.end(), t) - times.begin();

        return ind < n && times[ind] == t ? whoIsLeading[ind] : whoIsLeading[ind - 1];
    }
};
