// Removes duplicates using multiplication of
// distinct primes in array
#include <bits/stdc++.h>
using namespace std;

int removeDups(vector<int>& vect) {
  long long int prod = vect[0];
  int res_ind = 1;
  for (int i = 1; i < vect.size(); i++) {
    if (prod % vect[i] != 0) {
      vect[res_ind++] = vect[i];
      prod *= vect[i];
    }
  }
  vect.erase(vect.begin() + res_ind, vect.end());
}

// Driver code
int main() {
  vector<int> vect{3, 5, 7, 2, 2, 5, 7, 7};
  removeDups(vect);
  for (int i = 0; i < vect.size(); i++) cout << vect[i] << " ";
  return 0;
}
