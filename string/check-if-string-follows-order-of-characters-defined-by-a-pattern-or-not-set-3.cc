// C++ program to find if a string follows order
// defined by a given pattern.
#include <bits/stdc++.h>
using namespace std;

const int CHAR_SIZE = 256;

// Returns true if characters of str follow
// order defined by a given ptr.
bool checkPattern(string str, string pat) {
  // Initialize all orders as -1
  vector<int> label(CHAR_SIZE, -1);

  // Assign an order to pattern characters
  // according to their appearance in pattern
  int order = 1;
  for (int i = 0; i < pat.length(); i++) {
    // give the pattern characters order
    label[pat[i]] = order;

    // increment the order
    order++;
  }

  //  Now one by check if string characters
  // follow above order
  int last_order = -1;
  for (int i = 0; i < str.length(); i++) {
    if (label[str[i]] != -1) {
      // If order of this character is less
      // than order of previous, return false.
      if (label[str[i]] < last_order) return false;

      // Update last_order for next iteration
      last_order = label[str[i]];
    }
  }

  // return that str followed pat
  return true;
}

// Driver code
int main() {
  string str = "engineers rock";
  string pattern = "gsr";

  cout << boolalpha << checkPattern(str, pattern);

  return 0;
}
