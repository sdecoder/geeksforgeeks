// C program for print missing elements
#include<stdio.h>
#define LIMIT 100
 
// A O(n) function to print missing elements in an array
void printMissing(int arr[], int n)
{
    // Initialize all number from 0 to 99 as NOT seen
    bool seen[LIMIT] = {false};
 
    // Mark present elements in range [0-99] as seen
    for (int i=0; i<n; i++)
      if (arr[i] < LIMIT)
       seen[arr[i]] = true;
 
    // Print missing element
    int i = 0;
    while (i < LIMIT)
    {
        // If i is missing
        if (seen[i] == false)
        {
            // Find if there are more missing elements after i
            int j = i+1;
            while (j < LIMIT && seen[j] == false)
                  j++;
 
            // Print missing single or range
            (i+1 == j)? printf("%d\n", i): printf("%d-%d\n", i, j-1);
 
            // Update u
            i = j;
        }
        else
            i++;
    }
}
 
// Driver program
int main()
{
    int arr[] = {88, 105, 3, 2, 200, 0, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMissing(arr, n);
    return 0;
}

