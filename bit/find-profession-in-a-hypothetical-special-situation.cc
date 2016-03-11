// C++ program to find profession of a person at
// given level and position.
#include <bits/stdc++.h>
using namespace std;

// Returns 'e' if profession of node at given level
// and position is engineer. Else doctor. The function
// assumes that given position and level have valid values.
char findProffesion(int level, int pos) {
  // Base case
  if (level == 1) return 'e';

  // Recursively find parent's profession. If parent
  // is a doctar, this node will be a doctal if it is
  // at odd position and an engineer if at even position
  if (findProffesion(level - 1, (pos + 1) / 2) == 'd') return (pos % 2) ? 'd' : 'e';

  // If parent is an engineer, then current node will be
  // an enginner if at add position and doctor if even
  // position.
  return (pos % 2) ? 'e' : 'd';
}

// Driver code
int main(void) {
  int level = 4, pos = 2;
  (findProffesion(level, pos) == 'e') ? cout << "Engineeer" : cout << "Doctor";
  return 0;
}
