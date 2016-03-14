// Program to find all combinations of Non-
// overlapping substrings formed from given
// string
#include <iostream>
using namespace std;
 
// find all combinations of non-overlapping
// substrings formed by input string str
// index – index of the next character to
//          be processed
// out - output string so far
void findCombinations(string str, int index,
                      string out)
{
    if (index == str.length())
        cout << out << endl;
 
    for (int i = index; i < str.length(); i ++)
 
        // append substring formed by str[index,
        // i] to output string
        findCombinations(str, i + 1, out +
          "(" + str.substr(index, i+1-index) + ")" );
}
 
// Driver Code
int main()
{
    // input string
    string str = "abcd";
 
    findCombinations(str, 0, "");
 
    return 0;
}

