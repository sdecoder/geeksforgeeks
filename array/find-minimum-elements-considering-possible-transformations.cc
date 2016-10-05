// C++ program to find count of minimum elements
// after considering all possible transformations.
#include <iostream>
using namespace std;
 
// Returns minium possible elements after considering
// all possible transformations.
int findMin(char arr[], int n)
{
    // Initialize counts of all colors as 0
    int b_count = 0, g_count = 0, r_count = 0;
 
    // Count number of elements of different colors
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'B') b_count++;
        if (arr[i] == 'G') g_count++;
        if (arr[i] == 'R') r_count++;
    }
 
    // Check if elements are of same color
    if (b_count==n || g_count==n || r_count==n)
        return n;
 
    // If all are odd, return 2
    if ((r_count&1 && g_count&1 && b_count&1) )
        return 2;
 
    // If all are even, then also return 2
    if (!(r_count & 1) && !(g_count & 1) &&
        !(b_count & 1) )
        return 2;
 
    // If none above the cases are true, return 1
    return 1;
}
 
// Driver code
int main()
{
    char arr[] = {'R', 'G', 'B', 'R'};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMin(arr, n);
    return 0;
}


