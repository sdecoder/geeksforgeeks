// C++ program to in-place replace multiple
// occurrences of a pattern by character ‘X’
#include <bits/stdc++.h>
using namespace std;
 
// returns true if pattern is prefix of str
bool compare(char* str, char* pattern)
{
    for (int i = 0; pattern[i]; i++)
        if (str[i] != pattern[i])
            return false;
    return true;
}
 
// Function to in-place replace multiple
// occurrences of a pattern by character ‘X’
void replacePattern(char *str, char* pattern)
{
    // If pattern is null or empty string,
    // nothing needs to be done
    if (pattern == NULL)
        return;
 
    int len = strlen(pattern);
    if (len == 0)
       return;
 
    int i = 0, j = 0;
    int count;
 
    // for each character
    while (str[j])
    {
        count = 0;
 
        // compare str[j..j+len] with pattern
        while (compare(str+j, pattern))
        {
            // increment j by length of pattern
            j = j + len;
            count++;
        }
 
        // If single or multiple occurrences of pattern
        // is found, replace it by character 'X'
        if (count > 0)
            str[i++] = 'X';
 
        // copy character at current position j
        // to position i and increment i and j
        if (str[j])
            str[i++] = str[j++];
    }
 
    // add a null character to terminate string
    str[i] = '\0';
}
 
// Driver code
int main()
{
    char str[] = "GeeksforGeeks";
    char pattern[] = "Geeks";
 
    replacePattern(str, pattern);
    cout << str;
 
    return 0;
}


