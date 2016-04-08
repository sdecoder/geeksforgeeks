// C program to check whether a given array
// represents a max-heap or not
#include <stdio.h>
#include <limits.h>

// Returns true if arr[i..n-1] represents a
// max-heap
bool isHeap(int arr[], int n) {
  // Start from root and go till the last internal
  // node
  for (int i = 0; i <= (n - 2) / 2; i++) {
    // If left child is greater, return false
    if (arr[2 * i + 1] > arr[i]) return false;

    // If right child is greater, return false
    if (arr[2 * i + 2] > arr[i]) return false;
  }
  return true;
}

// Driver program
int main() {
  int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
  int n = sizeof(arr) / sizeof(int);

  isHeap(arr, n) ? printf("Yes") : printf("No");

  return 0;
}
