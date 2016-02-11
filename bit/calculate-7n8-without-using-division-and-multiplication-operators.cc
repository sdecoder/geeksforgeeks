// C program to evaluate 7n/8 without using * and /
#include<stdio.h>
 
int multiplyBySevenByEight(unsigned int n)
{   
    /* Step 1) First multiply number by 7 i.e. 7n = (n << 3) -n
     * Step 2) Divide result by 8 */
   return ((n << 3) -n) >> 3;
}
 
/* Driver program to test above function */
int main()
{
    unsigned int n = 15;
    printf("%u", multiplyBySevenByEight(n));
    return 0;
}


