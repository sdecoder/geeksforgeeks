// C++ program to convert a string to uppercase
#include <iostream>
using namespace std;
 
// Converts a string to uppercase
string to_upper(string &in)
{
    for (int i = 0; i < in.length(); i++)
          if ('a' <= in[i] <= 'z')
              in[i] &= ~(1 << 5);
    return in;
}
 
// Driver code
int main()
{
   string str = "geeksforgeeks";
   cout << to_upper(str);
   return 0;
}


