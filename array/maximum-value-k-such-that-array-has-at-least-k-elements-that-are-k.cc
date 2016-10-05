// C++ program to find maximum possible value K such
// that array has atleast K elements that are greater
// than or equals to K.
#include <bits/stdc++.h>
using namespace std;
 
// Function to return maximum possible value K such
// that array has at-least K elements that are greater
// than or equals to K.
int findMaximumNum(unsigned int arr[], int n)
{
    // construct axillary array of size n + 1 and
    // initialize the array with 0
    vector<int> freq(n+1, 0);
 
    // store the frequency of elements of
    // input array in the axillary array
    for (int i = 0; i < n; i++)
    {
        // If element is smaller than n, update its
        // frequency
        if (arr[i] < n)
            freq[arr[i]]++;
 
        // Else increment count of elements greater
        // than n.
        else
            freq[n]++;
    }
 
    // sum stores number of elements in input array
    // that are greater than or equal to current
    // index
    int sum = 0;
 
    // scan auxillary array backwards
    for (int i = n; i > 0; i--)
    {
        sum += freq[i];
 
        // if sum is greater than current index,
        // current index is the answer
        if (sum >= i)
            return i;
    }
}
 
// Driver code
int main()
{
    unsigned int arr[] = {1, 2, 3, 8, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << findMaximumNum(arr, n);
 
    return 0;
}


