// C++ program to swap three variables
// without using temporary variable
#include <iostream>
using namespace std;

// Assign c's value to a, a's value to b and
// b's value to c.
void swapThree(int& a, int& b, int& c) {
  // Store XOR of all in a
  a = a ^ b ^ c;

  // After this, b has value of a
  b = a ^ b ^ c;

  // After this, c has value of b
  c = a ^ b ^ c;

  // After this, a has value of c
  a = a ^ b ^ c;
}

// Driver code
int main() {
  int a = 10, b = 20, c = 30;

  cout << "Before swapping a = " << a << ", b = " << b << ", c = " << c << endl;

  swapThree(a, b, c);

  cout << "After swapping a = " << a << ", b = " << b << ", c = " << c << endl;

  return 0;
}
