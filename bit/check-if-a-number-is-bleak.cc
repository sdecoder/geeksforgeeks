// A simple C++ program to check Bleak Number
#include <bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(int x) {
  unsigned int count = 0;
  while (x) {
    x &= (x - 1);
    count++;
  }
  return count;
}

// Returns true if n is Bleak
bool isBleak(int n) {
  // Check for all numbers 'x' smaller
  // than n.  If x + countSetBits(x)
  // becomes n, then n can't be Bleak
  for (int x = 1; x < n; x++)
    if (x + countSetBits(x) == n) return false;

  return true;
}

// Driver code
int main() {
  isBleak(3) ? cout << "Yes\n" : cout << "No\n";
  isBleak(4) ? cout << "Yes\n" : cout << "No\n";
  return 0;
}
