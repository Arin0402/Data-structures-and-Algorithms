// https://www.geeksforgeeks.org/check-if-the-given-string-is-shuffled-substring-of-another-string/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 256

bool compare(int arr1[], int arr2[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

bool search(char *str, char *txt)
{
    int m = strlen(str), n = strlen(txt);

    int countS[MAX] = {0}, countT[MAX] = {0};

    for (int i = 0; i < m; i++)
    {
        countS[str[i]]++;
        countT[txt[i]]++;
    }

    for (int i = m; i < n; i++)
    {

        if (compare(countS, countT, n))
            return true;

        countT[txt[i]]++;
        countT[txt[i - m]]--;
    }
    if (compare(countS, countT, n))
        return true;
    return false;

    return true;
}
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    if (search(pat, txt))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
