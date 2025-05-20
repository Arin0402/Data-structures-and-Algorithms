// Given a list of logs with IP addresses in the following format.
// lines = ["10.0.0.1 - GET 2020-08-24", "10.0.0.1 - GET 2020-08-24", "10.0.0.2 - GET 2020-08-20",
// "10.0.0.1 - GET 2020-08-24", "10.0.0.1 - GET 2020-08-24", "10.0.0.2 - GET 2020-08-20",
// "10.0.0.2 - GET 2020-08-24", "10.0.0.1 - GET 2020-08-24", "10.0.0.2 - GET 2020-08-20",
// "10.0.0.2 - GET 2020-08-24", "10.0.0.1 - GET 2020-08-24", "10.0.0.2 - GET 2020-08-20",
// "10.0.0.3 - GET 2020-08-24", "10.0.0.1 - GET 2020-08-24", "10.0.0.2 - GET 2020-08-20"]

// Return the most frequent IP address from the logs. The retuned IP address value must be in a string format. If multiple IP addresses have the count equal to max count, then return the address as a comma-separated string with IP addresses in sorted order.


#include <bits/stdc++.h>
using namespace std;

string mostFrequentIPs(vector<string>& lines) {
    unordered_map<string, int> ipCount;

    for (const string& line : lines) {
        int pos = line.find(' ');
        if (pos != string::npos) {
            string ip = line.substr(0, pos);
            ipCount[ip]++;
        }
    }

    // Find the max frequency
    int maxCount = 0;
    for (auto& pair : ipCount) {
        maxCount = max(maxCount, pair.second);
    }

    // Collect all IPs with max frequency
    vector<string> mostFrequent;
    for (auto& pair : ipCount) {
        if (pair.second == maxCount) {
            mostFrequent.push_back(pair.first);
        }
    }

    // Sort the IPs if there is a tie
    sort(mostFrequent.begin(), mostFrequent.end());
   
}

