// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
#include <iostream>
#include <queue>
using namespace std;

bool areRotations(string str1, string str2)
{
    // method 1
    if (str1.length() != str2.length())
    {
        return false;
    }
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

bool isrotated(string str1, string str2)
{
    // method 2

    queue<char> q1, q2;
    int n1 = str1.size();
    int n2 = str2.size();

    if (n1 != n2)
        return false;

    for (int i = 0; i < n1; i++)
    {
        q1.push(str1[i]);
        q2.push(str2[i]);
    }

    while (n2--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        if (q2 == q1)
            return true;
    }
    return false;
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";

    // if (areRotations(str1, str2))
    if (isrotated(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}