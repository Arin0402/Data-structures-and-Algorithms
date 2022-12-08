#include <iostream>
using namespace std;

#define N 4

void rotate90Clockwise(int arr[N][N])
{

    // Method one
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - 1 - i; j++)
        {
            int temp = arr[i][j];

            arr[i][j] = arr[N - j - 1][i];
            arr[N - j - 1][i] = arr[N - i - 1][N - j - 1];
            arr[N - i - 1][N - j - 1] = arr[j][N - i - 1];
            arr[j][N - i - 1] = temp;
        }
    }
}

void rotate90Clockwise_1(int arr[N][N], int n)
{

    // method 2
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void transposeofmatrix(int mat[N][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}

void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int arr[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate90Clockwise_1(arr, 4);
    // printMatrix(arr);
    return 0;
}