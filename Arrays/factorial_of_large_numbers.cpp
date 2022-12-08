#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void multiply(vector<int> &ans, int n)
    {

        int carry = 0;

        for (int i = 0; i < ans.size(); i++)
        {
            int prod = ans[i] * n + carry;

            ans[i] = prod % 10;
            carry = prod / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    vector<int> factorial(int N)
    {

        vector<int> ans;
        ans.push_back(1);

        for (int i = 2; i <= N; i++)
        {
            multiply(ans, i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = s.factorial(6);
}