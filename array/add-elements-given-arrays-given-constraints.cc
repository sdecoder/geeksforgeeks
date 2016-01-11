// C++ program to add two arrays following given
// constraints
#include <bits/stdc++.h>
using namespace std;

// Function to push individual digits of a number
// to output vector from left to right
void split(int num, vector<int>& out) {
  vector<int> arr;
  while (num) {
    arr.push_back(num % 10);
    num = num / 10;
  }
  // reverse the vector arr and append it to output vector
  out.insert(out.end(), arr.rbegin(), arr.rend());
}

// Function to add two arrays keeping given
// constraints
void addArrays(int arr1[], int arr2[], int m, int n) {
  // create a vector to store output
  vector<int> out;

  // maintain a variable to store current index in
  // both arrays
  int i = 0;

  // loop till arr1 or arr2 runs out
  while (i < m && i < n) {
    // read next elements from both arrays and
    // add them
    int sum = arr1[i] + arr2[i];

    // if sum is single digit number
    if (sum < 10)
      out.push_back(sum);

    else {
      // if sum is not a single digit number, push
      // individual digits to output vector
      split(sum, out);
    }

    // increment to next index
    i++;
  }

  // push remaining elements of first input array
  // (if any) to output vector
  while (i < m) split(arr1[i++], out);

  // push remaining elements of second input array
  // (if any) to output vector
  while (i < n) split(arr2[i++], out);

  // print the output vector
  for (int x : out) cout << x << " ";
}

// Driver code
int main() {
  int arr1[] = {9343, 2, 3, 7, 9, 6};
  int arr2[] = {34, 11, 4, 7, 8, 7, 6, 99};

  int m = sizeof(arr1) / sizeof(arr1[0]);
  int n = sizeof(arr2) / sizeof(arr2[0]);

  addArrays(arr1, arr2, m, n);

  return 0;
}
