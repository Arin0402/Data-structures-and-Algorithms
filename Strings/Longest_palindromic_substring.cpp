// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
#include <iostream>
#include <cstring>
using namespace std;

string largestPalindromicSubstring(string s)
{

    // method 1
    // Dynamic programming
    // O(n^2) and O(n^2) extra space
    int n = s.size();

    bool mat[n][n];
    memset(mat, false, sizeof(mat));

    cout << sizeof(mat) << endl;
    for (int i = 0; i < n; i++)
        mat[i][i] = true;

    string longest_substring = "";

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            mat[i][i + 1] = true;
            longest_substring = s.substr(i, 2);
        }
    }

    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            // cout << j << " " << i + j - 1 << endl;
            if (s[j] == s[i + j - 1] && mat[j + 1][i + j - 2])
            {
                mat[j][i + j - 1] = true;
                // cout << s.substr(j, i) << endl;
                if (longest_substring.length() < i)
                    longest_substring = s.substr(j, i);
            }
        }
    }
    return longest_substring;
}

void longestPalSubstr(string str)
{
    // method 2
    // O(n^2) and O(1) extra space

    int n = str.size();

    if (n < 2)
        cout << str << endl;

    int low, high, maxlength = 1, start = 0;

    for (int i = 0; i < n; i++)
    {

        low = i - 1;
        high = i + 1;

        while (high < n && str[high] == str[i])
            high++;
        while (low >= 0 && str[low] == str[i])
            low--;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            low--;
            high++;
        }

        int length = high - low - 1;
        if (maxlength < length)
        {
            maxlength = length;
            start = low + 1;
        }
    }

    cout << str.substr(start, maxlength) << endl;
    ;
}
int main()
{
    string s = "sdfabccbadsf";
    // cout<< largestPalindromicSubstring(s) << endl;
    longestPalSubstr(s);
}