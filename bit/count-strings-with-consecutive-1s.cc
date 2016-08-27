#include <iostream>
using namespace std;

// Returns count of n length binary strings with
// consecutive 1's
int countStrings(int n) {
  // Count binary strings without consecutive 1's.
  // See the approach discussed on be
  // ( http://goo.gl/p8A3sW )
  int a[n], b[n];
  a[0] = b[0] = 1;
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] + b[i - 1];
    b[i] = a[i - 1];
  }

  // Subtract a[n-1]+b[n-1] from 2^n
  return (1 << n) - a[n - 1] - b[n - 1];
}

// Driver program to test above functions
int main() {
  cout << countStrings(5) << endl;
  return 0;
}
