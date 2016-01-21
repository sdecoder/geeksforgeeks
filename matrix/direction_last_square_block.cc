// C++ program to tell the Current direction in
// R x C grid
#include <iostream>
using namespace std;
typedef long long int ll;

// Function which tells the Current direction
void direction(ll R, ll C) {
  if (R != C && R % 2 == 0 && C % 2 != 0 && R < C) {
    cout << "Left" << endl;
    return;
  }
  if (R != C && R % 2 != 0 && C % 2 == 0 && R > C) {
    cout << "Up" << endl;
    return;
  }
  if (R == C && R % 2 != 0 && C % 2 != 0) {
    cout << "Right" << endl;
    return;
  }
  if (R == C && R % 2 == 0 && C % 2 == 0) {
    cout << "Left" << endl;
    return;
  }
  if (R != C && R % 2 != 0 && C % 2 != 0 && R < C) {
    cout << "Right" << endl;
    return;
  }
  if (R != C && R % 2 != 0 && C % 2 != 0 && R > C) {
    cout << "Down" << endl;
    return;
  }
  if (R != C && R % 2 == 0 && C % 2 == 0 && R < C) {
    cout << "Left" << endl;
    return;
  }
  if (R != C && R % 2 == 0 && C % 2 == 0 && R > C) {
    cout << "Up" << endl;
    return;
  }
  if (R != C && R % 2 == 0 && C % 2 != 0 && R > C) {
    cout << "Down" << endl;
    return;
  }
  if (R != C && R % 2 != 0 && C % 2 == 0 && R < C) {
    cout << "Right" << endl;
    return;
  }
}

// Driver program to test the Cases
int main() {
  ll R = 3, C = 1;
  direction(R, C);
  return 0;
}
