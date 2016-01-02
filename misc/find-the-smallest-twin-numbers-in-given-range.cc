// C++ program to find the smallest twin in given range
#include <bits/stdc++.h>
using namespace std;
 
void printTwins(int low, int high)
{
    // Create a boolean array "prime[0..high]" and initialize
    // all entries it as true. A value in prime[i] will finally
    // be false if i is Not a prime, else true.
    bool prime[high+1];
    memset(prime, true, sizeof(prime));
 
    prime[0] = prime[1] = false;
 
    // Look for the smallest twin
    for (int p=2; p<=floor(sqrt(high))+1; p++)
    {
        // If p is not marked, then it is a prime
        if (prime[p])
        {
            // Update all multiples of p
            for (int i=p*2; i<=high; i += p)
                prime[i] = false;
        }
    }
 
    // Now print the smallest twin in range
    for (int i=low; i<=high; i++)
    {
        if (prime[i] && prime[i+2])
        {
            cout << "Smallest twins in given range: ("
                 << i << ", " << i+2 <<  ")";
            break;
        }
    }
}
 
// Driver program
int main()
{
    printTwins(10, 100);
    return 0;
}


