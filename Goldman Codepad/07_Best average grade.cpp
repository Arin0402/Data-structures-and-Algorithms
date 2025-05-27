// https://www.geeksforgeeks.org/find-maximum-average-marks-in-student-pairs/

// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Method to return maximum average marks
int findMaxAverageMarks(vector<pair<string, string> >& A)
{

    // Variable to store the max avergae
    int maxAvg = INT_MIN;

    // If A is empty, then
    // returning 0 as max average
    if (A.empty())
        return 0;

    // Map to store name and Pair<Total Marks,
    // frequency of student name>
    unordered_map<string, pair<int, int> > Map;

    // Initializing map by iterating over A
    for (auto& current_student : A) {

        // name of student
        string studentName = current_student.first;

        // Marks of student
        int marks = stoi(current_student.second);

        // Storing name and total marks of student
        // using pair
        if (Map.find(studentName) == Map.end()) {
            Map[studentName] = make_pair(0, 0);
        }

        Map[studentName].first += marks;
        Map[studentName].second += 1;
    }

    // Loop for Iterating over map
    for (const auto& entry : Map) {

        // total marks
        double totalScore = entry.second.first;

        // Number of times student appeared in A
        int count = entry.second.second;

        // Updating maxAvg if avergare(total/count) is
        // greater than maxAvg
        maxAvg = max(maxAvg, (int)(totalScore / count));
    }

    // Returning the max average
    return maxAvg;
}

// Driver Function
int main()
{
    // Input
    vector<pair<string, string> > A
        = { { "Bob", "87" }, { "Mike", "35" },
            { "Bob", "52" }, { "Jason", "35" },
            { "Mike", "55" }, { "Jessica", "99" } };

    // Function Call
    cout << findMaxAverageMarks(A) << endl;

    return 0;
}