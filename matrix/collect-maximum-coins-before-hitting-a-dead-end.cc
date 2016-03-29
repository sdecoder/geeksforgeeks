// A Naive Recursive C++ program to find maximum number of coins
// that can be collected before hitting a dead end
#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5

// to check whether current cell is out of the grid or not
bool isValid(int i, int j) {
  return (i >= 0 && i < R && j >= 0 && j < C);
}

// dir = 0 for left, dir = 1 for facing right.  This function returns
// number of maximum coins that can be collected starting from (i, j).
int maxCoinsRec(char arr[R][C], int i, int j, int dir) {
  // If this is a invalid cell or if cell is a blocking cell
  if (isValid(i, j) == false || arr[i][j] == '#') return 0;

  // Check if this cell contains the coin 'C' or if its empty 'E'.
  int result = (arr[i][j] == 'C') ? 1 : 0;

  // Get the maximum of two cases when you are facing right in this cell
  if (dir == 1)                                         // Direction is right
    return result + max(maxCoinsRec(arr, i + 1, j, 0),  // Down
                        maxCoinsRec(arr, i, j + 1, 1)); // Ahead in right

  // Direction is left
  // Get the maximum of two cases when you are facing left in this cell
  return result + max(maxCoinsRec(arr, i + 1, j, 1),  // Down
                      maxCoinsRec(arr, i, j - 1, 0)); // Ahead in left
}

// Driver program to test above function
int main() {
  char arr[R][C] = {{'E', 'C', 'C', 'C', 'C'}, {'C', '#', 'C', '#', 'E'},
      {'#', 'C', 'C', '#', 'C'}, {'C', 'E', 'E', 'C', 'E'}, {'C', 'E', '#', 'C', 'E'}};

  // As per the question initial cell is (0, 0) and direction is
  // right
  cout << "Maximum number of collected coins is " << maxCoinsRec(arr, 0, 0, 1);

  return 0;
}
