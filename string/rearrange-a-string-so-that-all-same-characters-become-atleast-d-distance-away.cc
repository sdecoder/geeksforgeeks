// C++ program to rearrange a string so that all same
// characters become atleast d distance away
#include <bits/stdc++.h>
#define MAX_CHAR 256
using namespace std;

// The function returns next eligible character
// with maximum frequency (Greedy!!) and
// zero or negative distance
int nextChar(int freq[], int dist[]) {
  int max = INT_MIN;
  for (int i = 0; i < MAX_CHAR; i++)
    if (dist[i] <= 0 && freq[i] > 0 && (max == INT_MIN || freq[i] > freq[max])) max = i;

  return max;
}

// The main function that rearranges input string 'str'
// such that two same characters become atleast d
// distance away
int rearrange(char str[], char out[], int d) {
  // Find length of input string
  int n = strlen(str);

  // Create an array to store all characters and their
  // frequencies in str[]
  int freq[MAX_CHAR] = {0};

  // Traverse the input string and store frequencies
  // of all characters in freq[] array.
  for (int i = 0; i < n; i++) freq[str[i]]++;

  // Create an array for inserting the values at
  // correct distance dist[j] stores the least distance
  // between current position and the next position we
  // can use character 'j'
  int dist[MAX_CHAR] = {0};

  for (int i = 0; i < n; i++) {
    // find next eligible character
    int j = nextChar(freq, dist);

    // return 0 if string cannot be rearranged
    if (j == INT_MIN) return 0;

    // Put character j at next position
    out[i] = j;

    // decrease its frequency
    freq[j]--;

    // set distance as d
    dist[j] = d;

    // decrease distance of all characters by 1
    for (int i = 0; i < MAX_CHAR; i++) dist[i]--;
  }

  // null terminate output string
  out[n] = '\0';

  // return success
  return 1;
}

// Driver code
int main() {
  char str[] = "aaaabbbcc";
  int n = strlen(str);

  // To store output
  char out[n];

  if (rearrange(str, out, 2))
    cout << out;
  else
    cout << "Cannot be rearranged";

  return 0;
}
