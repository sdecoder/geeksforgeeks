// C++ program to find maximum average subarray
// of given length.
#include<bits/stdc++.h>
using namespace std;
 
// Returns beginning index of maximum average
// subarray of length 'k'
int findMaxAverage(int arr[], int n, int k)
{
    // Check if 'k' is valid
    if (k > n)
        return -1;
 
    // Compute sum of first 'k' elements
    int sum = arr[0];
    for (int i=1; i<k; i++)
        sum += arr[i];
 
    int max_sum = sum, max_end = k-1;
 
    // Compute sum of remaining subarrays
    for (int i=k; i<n; i++)
    {
        int sum = sum + arr[i] - arr[i-k];
        if (sum > max_sum)
        {
            max_sum = sum;
            max_end = i;
        }
    }
 
    // Return starting index
    return max_end - k + 1;
}
 
// Driver program
int main()
{
    int arr[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The maximum average subarray of "
         "length "<< k << " begins at index "
         << findMaxAverage(arr, n, k);
    return 0;
}

