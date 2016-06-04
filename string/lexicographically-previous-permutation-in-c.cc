// C++ program to print all permutations with
// duplicates allowed using prev_permutation()
#include <bits/stdc++.h>
using namespace std;
 
// Function to compute the previous permutation
bool prevPermutation(string &str)
{
    // Find index of the last element of the string
    int n = str.length() – 1;
 
    // Find largest index i such that str[i ? 1] >
    // str[i]
    int i = n;
    while (i > 0 && str[i – 1] <= str[i])
        i–;
 
    // if string is sorted in ascending order
    // we’re at the last permutation
    if (i <= 0)
        return false;
 
    // Note – str[i..n] is sorted in ascending order
 
    // Find rightmost element’s index that is less
    // than str[i – 1]
    int j = i – 1;
    while (j + 1 <= n && str[j + 1] <= str[i – 1])
        j++;
 
    // Swap character at i-1 with j
    swap(str[i – 1], str[j]);
 
    // Reverse the substring [i..n]
    reverse(str.begin() + i, str.end());
 
    return true;
}
 
// Driver code
int main()
{
    string str = "4321";
    if ( prevPermutation(str) )
        cout << "Previous permutation is "<< str ;
    else
        cout << "Previous permutation doesn’t exist" ;
    return 0;
}

