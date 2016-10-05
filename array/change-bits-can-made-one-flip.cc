//Change if all bits can be made same by single flip
// Idea is to add the integer value all the elements
// in the given string.
// If the sum is 1 it indicates that there is
//    only single '1' in the string.
// If the sum is 0 it indicates that there is only
//    single '0' in the string.
// It takes O(n) time.
 
#include <bits/stdc++.h>
using namespace std;
 
bool isOneFlip(string str)
{
    int sum = 0;
    int n = str.length();
 
    // Traverse through given string and
    // count the total sum of numbers
    for( int i=0 ; i<n; i++)
        sum += str[i] - '0';
 
    // Return true if any of the two counts
    // is 1
    return (sum == n-1 || sum == 1);
}
 
//Main function
int main()
{
    isOneFlip("101111111111")? printf("Yes\n") : 
                               printf("No\n");
 
    return 0;
}


