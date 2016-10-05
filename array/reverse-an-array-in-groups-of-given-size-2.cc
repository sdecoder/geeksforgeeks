// C++ program to reverse every sub-array formed by 
// consecutive k elements where k doubles itself with 
// every sub-array.
#include <iostream>
using namespace std;
 
// Function to reverse every sub-array formed by 
// consecutive k elements where k doubles itself 
// with every sub-array.
void reverse(int arr[], int n, int k)
{
    // increment i in multiples of k where value
    // of k is doubled with each iteration
    for (int i = 0; i < n; i += k/2)
    {
        int left = i;
 
        // to handle case when number of elements in 
        // last group is less than k
        int right = min(i + k - 1, n - 1);
 
        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);
 
        // double value of k with each iteration
        k = k*2;
    }
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int k = 1;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    reverse(arr, n, k);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}


