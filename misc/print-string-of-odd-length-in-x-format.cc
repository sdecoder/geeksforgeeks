// C++ program to print Cross pattern
#include<iostream>
using namespace std;
 
// Function to print given string in cross pattern
// Length of string must be odd
void printPattern(string str)
{
    int len = str.length();
 
    // i goes from 0 to len and j goes from len-1 to 0
    for (int i=0,j=len-1; i<=len,j>=0; i++,j--)
    {
        // To print the upper part. This loop runs
        // til middle point of string (i and j become
        // same
        if (i<j)
        {
            // Print i spaces
            for (int x=0; x<i; x++)
                cout << " ";
 
            // Print i'th character
            cout << str[i];
 
            // Print j-i-1 spaces
            for (int x=0; x<j-i-1; x++)
                cout << " ";
 
            // Print j'th character
            cout << str[j] << endl;
        }
 
        // To print center point
        if (i==j)
        {
            // Print i spaces
            for (int x=0; x<i; x++)
                cout << " ";
 
            // Print middle character
            cout << str[i] << endl;
        }
 
        // To print lower part
        else if (i>j)
        {
            // Print j spances
            for (int x = j-1; x>=0; x--)
                cout << " ";
 
            // Print j'th character
            cout << str[j];
 
            // Print i-j-1 spaces
            for (int x=0; x<i-j-1; x++)
                cout << " ";
 
            // Print i'h character
            cout << str[i] << endl;
        }
    }
}
 
// Driver program
int main()
{
    printPattern("geeksforgeeks");
    return 0;
}


