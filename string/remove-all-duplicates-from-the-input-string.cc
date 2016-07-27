// C++ prigram to remove duplicates, the order of
// characters is not maintained in this program
#include<bits/stdc++.h>
using namespace std;

/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str)
{
    int res_ind = 1, ip_ind = 1;

    /* In place removal of duplicate characters*/
    while (*(str + ip_ind))
    {
        if (*(str + ip_ind) != *(str + ip_ind - 1))
        {
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }

    /* After above step string is stringiittg.
       Removing extra iittg after string*/
    *(str + res_ind) = '\0';

    return str;
}

/* Function removes duplicate characters from the string
   This function work in-place and fills null characters
   in the extra space left */
char *removeDups(char *str)
{
   int n = strlen(str);

   // Sort the character array
   sort(str, str+n);

   // Remove duplicates from sorted
   return removeDupsSorted(str);
}

/* Driver program to test removeDups */
int main()
{
  char str[] = "geeksforgeeks";
  cout << removeDups(str);
  return 0;
}


