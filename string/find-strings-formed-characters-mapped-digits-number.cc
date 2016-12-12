// C++ program to find all strings formed from a given
// number where each digit maps to given characters.
#include <bits/stdc++.h>
using namespace std;

// Function to find all strings formed from a given
// number where each digit maps to given characters.
vector<string> findCombinations(vector<int> input, vector<char> table[]) {
  // vector of strings to store output
  vector<string> out, temp;

  // stores index of first occurrence
  // of the digits in input
  unordered_map<int, int> mp;

  // maintains index of current digit considered
  int index = 0;

  // for each digit
  for (int d : input) {
    // store index of first occurrence
    // of the digit in the map
    if (mp.find(d) == mp.end()) mp[d] = index;

    // clear vector contents for future use
    temp.clear();

    // do for each character thats maps to the digit
    for (int i = 0; i < table[d - 1].size(); i++) {
      // for first digit, simply push all its
      // mapped characters in the output list
      if (index == 0) {
        string s(1, table[d - 1].at(i));
        out.push_back(s);
      }

      // from second digit onwards
      if (index > 0) {
        // for each string in output list
        // append current character to it.
        for (string str : out) {
          // convert current character to string
          string s(1, table[d - 1].at(i));

          // Imp - If this is not the first occurrence
          // of the digit, use same character as used
          // in its first occurrence
          if (mp[d] != index) s = str[mp[d]];

          str = str + s;

          // store strings formed by current digit
          temp.push_back(str);
        }

        // nothing more needed to be done if this
        // is not the first occurrence of the digit
        if (mp[d] != index) break;
      }
    }

    // replace contents of output list with temp list
    if (index > 0) out = temp;
    index++;
  }

  return out;
}

// Driver program
int main() {
  // vector to store the mappings
  vector<char> table[] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'},
      {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'Q', 'R'}, {'S', 'T', 'U'}, {'V', 'W', 'X'},
      {'Y', 'Z'}};

  // vector to store input number
  vector<int> input = {1, 2, 1};

  vector<string> out = findCombinations(input, table);

  // print all possible strings
  for (string it : out) cout << it << " ";

  return 0;
}
