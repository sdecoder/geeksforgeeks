#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;
 
// A structure to represent a cell index
struct Cell
{ 
    int r; // r is row, varies from 0 to R-1
    int c; // c is column, varies from 0 to C-1
};
 
// A simple solution to find sums for a given array of cell indexes
void printSums(int mat[][C], struct Cell arr[], int n)
{
    // Iterate through all cell indexes
    for (int i=0; i<n; i++)
    {
        int sum = 0, r = arr[i].r, c = arr[i].c;
 
        // Compute sum for current cell index
        for (int j=0; j<R; j++)
            for (int k=0; k<C; k++)
                if (j != r && k != c)
                    sum += mat[j][k];
        cout << sum << endl;
    }
}
 
// Driver program to test above
int main()
{
    int mat[][C] = {{1, 1, 2}, {3, 4, 6}, {5, 3, 2}};
    struct Cell arr[] = {{0, 0}, {1, 1}, {0, 1}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSums(mat, arr, n);
    return 0;
}
