#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        for (auto c : s)
        {

            switch (c)
            {
            case '(':
                st.push(')');
                break; // put the corresponding pair in the stack.
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            default: // check if the top is same or not.
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};