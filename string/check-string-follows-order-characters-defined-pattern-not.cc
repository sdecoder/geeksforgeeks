// C++ program check if characters in the input string 
// follows the same order as determined by characters 
// present in the given pattern
#include <iostream>
using namespace std;
  
// Function to check if characters in the input string 
// follows the same order as determined by characters 
// present in the given pattern
bool checkPattern(string str, string pattern)
{
    // len stores length of the given pattern 
    int len = pattern.length();
      
    // if length of pattern is more than length of 
    // input string, return false;
    if (str.length() < len)
        return false;
      
    for (int i = 0; i < len - 1; i++) 
    {
        // x, y are two adjacent characters in pattern
        char x = pattern[i];
        char y = pattern[i + 1];
         
        // find index of last occurrence of character x
        // in the input string
        size_t last = str.find_last_of(x);
          
        // find index of first occurrence of character y
        // in the input string
        size_t first = str.find_first_of(y);
          
        // return false if x or y are not present in the 
        // input string OR last occurrence of x is after 
        // the first occurrence of y in the input string
        if (last == string::npos || first ==  
            string::npos || last > first)    
        return false;
    }
      
    // return true if string matches the pattern
    return true;
}
 
// Driver code
int main()
{
    string str = "engineers rock";
    string pattern = "gsr";
  
    cout << boolalpha << checkPattern(str, pattern);
  
    return 0;
}


