// C++ program to find number of consecutive
// 0s in a sequence
#include<bits/stdc++.h>
using namespace std;
 
// Function to find number of consecutive Zero Pairs
// Here n is number of steps
int consecutiveZeroPairs(int n)
{
    // Base cases
    if (n==1)
        return 0;
    if (n==2 || n==3)
        return 1;
 
    // Calculating how many times divisible by 12, i.e.,
    // count total number repeating segments of length 12
    int q = (pow(2,n) / 12);
 
    // number of consecutive Zero Pairs
    return 2*q + 1;
}
 
// Driver program to run the test case
int main()
{
    int n = 5;
    cout << consecutiveZeroPairs(n) << endl;
    return 0;
}



