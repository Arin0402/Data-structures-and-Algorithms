#include <bits/stdc++.h>
using namespace std;

// 1
// Naive.
// Try out every rotation for the first string and compare.
// create a partition in one string and increase it by one character.
// compare the two strings.
// one string starting after the partition index to the index before partiton.
// one string starting from index 0 to the end.
// O(N^2) (comparing the strings every time takes O(N));

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        // both strings are unequal.
        if (s1.size() != s2.size())
            return 0;

        int p1 = 0; // partiton index.
        int n = s1.size();

        while (p1 < n)
        {

            // partition character is same.
            if (s1[p1] == s2[0])
            {

                bool found = true;

                // compare the two strings.
                for (int i = 0; i < n; i++)
                {

                    // differnet characters.
                    if (s1[(p1 + i) % n] != s2[i])
                    {
                        found = false;
                        break;
                    }
                }

                if (found)
                    return 1;
                else
                    p1++;
            }

            // different character so move the partiton.
            else
                p1++;
        }

        return 0;
    }
};

// 2
// using queues
// O(N^2)

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        // both strings are unequal.
        if (s1.size() != s2.size())
            return 0;

        queue<char> q1, q2;
        int n = s1.size();

        for (int i = 0; i < n; i++)
            q1.push(s1[i]);
        for (int i = 0; i < n; i++)
            q2.push(s2[i]);

        for (int i = 0; i < n; i++)
        {

            // queus are equal
            if (q1 == q2)
                return 1;

            // pop first element of the q1 and push it back.
            // so this way try out every rotation.
            char x = q1.front();

            q1.pop();
            q1.push(x);
        }

        return 0;
    }
};

// 3
// efiicient approach
// O(N)

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return 0;

        // create a temp array by adding string first two times.
        // if the string 2 is a rotaion of string first then it would be present in the temp string.

        string temp = s1 + s1;

        // time complexity of find is O(N);
        return temp.find(s2) != string::npos;
    }
};