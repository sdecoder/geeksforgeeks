// C++ program to count minimum palindromic subsequences
// to be removed to make an string empty.
#include <bits/stdc++.h>
using namespace std;
 
// A function to check if a string str is palindrome
bool isPalindrome(const char *str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
        if (str[l++] != str[h--])
            return false;
 
    return true;
}
 
// Returns count of minimum palindromic subseuqnces to
// be removed to make string empty
int minRemovals(const char *str)
{
   // If string is empty
   if (str[0] == '\0')
      return 0;
 
   // If string is palindrome
   if (isPalindrome(str))
      return 1;
 
   // If string is not palindrome
   return 2;
}
 
// Driver code to test above
int main()
{
   cout << minRemovals("010010") << endl;
   cout << minRemovals("0100101") << endl;
   return 0;
}


