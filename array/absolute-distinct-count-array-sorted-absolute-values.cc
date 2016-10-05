// Program to find absolute distinct
// count of an array using O(1) space.
#include <bits/stdc++.h>
using namespace std;
 
// The function returns return number
// of distinct absolute values
// among the elements of the array
int distinctCount(int arr[], int n)
{
    // initialize count as number of elements
    int count = n;
    int i = 0, j = n - 1, sum = 0;
 
    while (i < j)
    {
        // Remove duplicate elements from the
        // left of the current window (i, j)
        // and also decrease the count
        while (i != j && arr[i] == arr[i + 1])
            count--, i++;
 
        // Remove duplicate elements from the
        // right of the current window (i, j)
        // and also decrease the count
        while (i != j && arr[j] == arr[j - 1])
            count--, j--;
 
        // break if only one element is left
        if (i == j)
            break;
 
        // Now look for the zero sum pair
        // in current window (i, j)
        sum = arr[i] + arr[j];
 
        if (sum == 0)
        {
            // decrease the count if (positive,
            // negative) pair is encountered
            count--;
            i++, j--;
        }
        else if(sum < 0)
            i++;
        else
            j--;
    }
 
    return count;
}
 
// Driver code
int main()
{
    int arr[] = {-2, -1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Count of absolute distinct values : "
         << distinctCount(arr, n);
 
    return 0;
}


