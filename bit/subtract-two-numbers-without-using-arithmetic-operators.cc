#include <stdio.h>

int subtract(int x, int y) {
  if (y == 0) return x;
  return subtract(x ^ y, (~x & y) << 1);
}

// Driver program
int main() {
  int x = 29, y = 13;
  printf("x - y is %d", subtract(x, y));
  return 0;
}
