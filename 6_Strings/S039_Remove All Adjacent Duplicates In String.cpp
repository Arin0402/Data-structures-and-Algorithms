#include <bits/stdc++.h>
using namespace std;

// IMP
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s) {

        // stack to store characters.
        stack<char> st;

        for(int i = 0; i < s.size(); i++){        
            // stack empty.
            if(st.empty()) st.push(s[i]);

            // same charcters.
            else if(st.top() == s[i]) st.pop();

            // different characters.            
            else st.push(s[i]);
        }

        // generate the output.
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());

        return s;

    }
};

// 2
// using the string as a vector

class Solution {
public:
	string removeDuplicates(string s) {

		string ans;
		ans.push_back(s[0]);

		for(int i=1 ; i<s.length() ; i++){

			if(!ans.empty() && s[i] == ans.back()){
				ans.pop_back();
			}
			else{
				ans.push_back(s[i]);
			}
		}

		return ans;
	}
};