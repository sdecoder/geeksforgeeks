// C++ program to find the maximum product of a subarray
// of size k.
#include <bits/stdc++.h>
using namespace std;

// This function returns maximum product of a subarray
// of size k in given arrar, arr[0..n-1]. This function
// assumes that k is smaller than or equal to n.
int findMaxProduct(int arr[], int n, int k) {
  // Initialize the MaxProduct to 1, as all elements
  // in the array are positive
  int MaxProduct = 1;
  for (int i = 0; i < k; i++) MaxProduct *= arr[i];

  int prev_product = MaxProduct;

  // Consider every product beginning with arr[i]
  // where i varies from 1 to n-k-1
  for (int i = 1; i <= n - k; i++) {
    int curr_product = (prev_product / arr[i - 1]) * arr[i + k - 1];
    MaxProduct = max(MaxProduct, curr_product);
    prev_product = curr_product;
  }

  // Return the maximum product found
  return MaxProduct;
}

// Driver code
int main() {
  int arr1[] = {1, 5, 9, 8, 2, 4, 1, 8, 1, 2};
  int k = 6;
  int n = sizeof(arr1) / sizeof(arr1[0]);
  cout << findMaxProduct(arr1, n, k) << endl;

  k = 4;
  cout << findMaxProduct(arr1, n, k) << endl;

  int arr2[] = {2, 5, 8, 1, 1, 3};
  k = 3;
  n = sizeof(arr2) / sizeof(arr2[0]);
  cout << findMaxProduct(arr2, n, k);

  return 0;
}
