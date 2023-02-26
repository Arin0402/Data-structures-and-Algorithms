#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

// 1
// using stl functions
class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }      
        return s;
    }
};

// 2
// this is a part of string matching problem.
// we can use kmp algorithm to find each occurence of the pattern in text and then can remove it.