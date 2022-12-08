#include <iostream>
#include <unordered_map>
using namespace std;
#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{

    unordered_map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        mp[mat[0][i]] = 1;
    }

    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i + 1;

                if (i == M - 1 && mp[mat[i][j]] == M)
                {
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
}
int main()
{
    int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat);

    return 0;
}
