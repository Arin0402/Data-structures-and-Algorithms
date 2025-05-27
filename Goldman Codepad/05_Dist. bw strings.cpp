/*

Given a String and two words (which occur in the given string), find the minimum distance between two words. Distance between two words is defined as the number of characters between the given two words’ middle characters. The brute-force approach was already implemented but it had some logical bugs, and because of which sample test cases were failing. The objective was to find and fix those bugs and then to add some new test cases and write a code for those test cases as well.

*/
/*
#include <bits/stdc++.h>
#include<boost/algorithm/string.hpp>
using namespace std;

double shortestDistance(const string& document, const string& word1, const string& word2) {
    vector<string> words;
    boost::split(words, document, boost::is_any_of(" .,"));

    int index = 0;
    int shortest = document.length();
    int word1_loc = -1;
    int word2_loc = -1;

    for (const string& word : words) {
        if (boost::iequals(word, word1)) {
            word1_loc = index + (word.length() - 1) / 2;
        } else if (boost::iequals(word, word2)) {
            word2_loc = index + (word.length() - 1) / 2;
        }

        if (word1_loc != -1 && word2_loc != -1) {
            int current = abs(word1_loc - word2_loc) - 1;
            if (current < shortest) {
                shortest = current;
            }
        }

        index += word.length() + 1; // assumes one space/punctuation
    }

    if (word1_loc == -1 || word2_loc == -1)
        return -1;

    return shortest;
}
*/