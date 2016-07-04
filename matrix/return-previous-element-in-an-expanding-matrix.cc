// Program to return previous element in an expanding
// matrix.
#include <bits/stdc++.h>
using namespace std;

// Returns left of str in an expanding matrix of
// a, b, c  and d.
string findLeft(string str) {
  int n = str.length();

  // Start from rightmost position
  while (n--) {
    // If the current character is ‘b’ or ‘d’,
    // change to ‘a’ or ‘c’ respectively and
    // break the loop
    if (str[n] == 'd') {
      str[n] = 'c';
      break;
    }
    if (str[n] == 'b') {
      str[n] = 'a';
      break;
    }

    // If the current character is ‘a’ or ‘c’,
    // change it to ‘b’ or ‘d’ respectively
    if (str[n] == 'a')
      str[n] = 'b';
    else if (str[n] == 'c')
      str[n] = 'd';
  }

  return str;
}

// driver program to test above method
int main() {
  string str = "aacbddc";
  cout << "Left of " << str << " is " << findLeft(str);
  return 0;
}
