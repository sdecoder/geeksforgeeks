// C/C++ program to remove all adjacent duplicates
// from a string
#include <iostream>
#include <string.h>
using namespace std;
 
// This function recursively removes duplicates
// and returns modified string
char* removeDup(char * str, int n)
{
    int len = strlen(str);
    int k = 0; // To store index of result
 
    // Start from second character and add
    // unique ones
    for (int i=1; i< len; i++)
    {
        // If different, increment k and add
        // previous character
        if (str[i-1] != str[i])
            str[k++] = str[i-1];
 
        else
            // Keep skipping (removing) characters
            // while they are same.
            while (str[i-1] == str[i])
                i++;
    }
 
    // Add last character and terminator
    str[k++] = str[i-1];
    str[k] =  '\0';
 
    // Recur for string if there were some removed
    // character
    if (k != n)
        removeDup(str, k);// Shlemial Painter's Algorithm
 
    // If all characters were unique
    else return str;
}
 
int main()
{
    char str1[] = "geeksforgeeg";
    cout << removeDup(str1, strlen(str1)) << endl;
 
    char str2[] = "azxxxzy";
    cout << removeDup(str2, strlen(str2)) << endl;
 
    char str3[] = "caaabbbaac";
    cout << removeDup(str3, strlen(str3)) << endl;
 
    char str4[] = "gghhg";
    cout << removeDup(str4, strlen(str4)) << endl;
 
    char str5[] = "aaaacddddcappp";
    cout << removeDup(str5, strlen(str5)) << endl;
 
    char str6[] = "aaaaaaaaaa";
    cout << removeDup(str6, strlen(str6)) << endl;
 
    char str7[] = "qpaaaaadaaaaadprq";
    cout << removeDup(str7, strlen(str7)) << endl;
 
    char str8[] = "acaaabbbacdddd";
    cout << removeDup(str8, strlen(str8)) << endl;
 
    char str9[] = "acbbcddc";
    cout << removeDup(str9, strlen(str9)) << endl;
}
// This code is contributed by Aditya Goel.


