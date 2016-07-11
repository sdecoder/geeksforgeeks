// C++ program to find largest subarray with equal number of
// 0's and 1's.
#include <bits/stdc++.h>
using namespace std;
 
// Returns largest subarray with equal number of 0s and 1s
int maxLen(int arr[], int n)
{
    // Creates an empty hashMap hM
    unordered_map<int, int> hM;
 
    int sum = 0;     // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0)? -1: 1;
 
    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += arr[i];
 
        // To handle sum=0 at last index
        if (sum == 0)
        {
            max_len = i + 1;
            ending_index = i;
        }
 
        // If this sum is seen before, then update max_len
        // if required
        if (hM.find(sum + n) != hM.end())
        {
            if (max_len < i - hM[sum + n])
            {
                max_len = i - hM[sum + n];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum + n] = i;
    }
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1)? 0: 1;
 
    printf("%d to %d\n", ending_index-max_len+1, ending_index);
 
    return max_len;
}
 
// Driver method
int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    maxLen(arr, n);
    return 0;
}
// This code is contributed by Aditya Goel