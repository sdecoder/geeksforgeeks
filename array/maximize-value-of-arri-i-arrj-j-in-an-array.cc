// C++ program to find maximum value (arr[i]-i)
// - (arr[j]-j) in an array.
#include <bits/stdc++.h>
using namespace std;

// Returns maximum value of (arr[i]-i) - (arr[j]-j)
int findMaxDiff(int arr[], int n) {
  if (n < 2) {
    cout << "Invalid ";
    return 0;
  }

  // Find maximum of value of arr[i] - i for all
  // possible values of i. Let this value be max_val.
  // Find minimum of value of arr[i] - i for all
  // possible values of i. Let this value be min_val.
  // The difference max_val - min_v
  int min_val = INT_MAX, max_val = INT_MIN;
  for (int i = 0; i < n; i++) {
    if ((a[i] - i) > max_val) max_val = a[i] - i;
    if ((a[i] - i) < min_val) min_val = a[i] - i;
  }

  return (max_val - min_val);
}

// Driver program
int main() {
  int arr[] = {9, 15, 4, 12, 13};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findMaxDiff(arr, n);
  return 0;
}
